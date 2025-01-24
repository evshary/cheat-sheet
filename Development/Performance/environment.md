# Performance Environment

The page provides some tips to make the performance test result stable and trustable.

## Clean up the environment

* Stop unnecessary processes, like vscode, chrome, etc.
* Stop some default Ubuntu service
  * You can check the running service by `systemctl list-units --type=service --state=running`
  * Some service can be stopped

    ```shell
    # Automatically update
    sudo systemctl stop unattended-upgrades
    # snapd update
    sudo systemctl stop snapd
    # Kernel log collect
    sudo systemctl stop kerneloops
    # Printer service
    sudo systemctl stop cups
    sudo systemctl stop cups-browsed
    # Firmware update
    sudo systemctl stop fwupd
    # Modem
    sudo systemctl stop ModemManager
    # Reload
    sudo systemctl daemon-reload
    ```

## Fix CPU configuration

* CPU mode

```shell
# Show mode
cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor
# Set to performance mode
echo performance | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor
```

* CPU frequency

```shell
# Watch the CPU current frequency
watch -n 1 "cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_cur_freq"

# Show the max and min freq
cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq
cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq
for cpu in /sys/devices/system/cpu/cpu*/cpufreq/scaling_max_freq; do
    # Replace with the max freq
    echo 4700000 | sudo tee $cpu
done
for cpu in /sys/devices/system/cpu/cpu*/cpufreq/scaling_min_freq; do
    # Replace with the max freq
    echo 4700000 | sudo tee $cpu
done

# Back to original one afterward
for cpu in /sys/devices/system/cpu/cpu*/cpufreq/scaling_min_freq; do
    echo 800000 | sudo tee $cpu
done
```

* Disable trubo

```shell
# Show turbo configuration
cat /sys/devices/system/cpu/intel_pstate/no_turbo
# Disable turbo
echo "1" | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo
# Enable it back afterward
echo "0" | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo
```
