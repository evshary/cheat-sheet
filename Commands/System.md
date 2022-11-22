# CPU
* cpufrequtils
  - Should install `cpufrequtils` first.
  - `cpufreq-info`: Show the status of CPU
      - You can use `cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor`.
  - `cpufreq-set -r -g performance -c <CPU core>`: Set CPU to performance mode
  - Easier UI tool: `sudo apt install indicator-cpufreq`
* pidstat: Show which CPU core process run on.
* i7z: Show CPU freq, temp. and turbo mode
  - `sudo apt install i7z`
  - `sudo i7z`
* [system-monitor extension](http://ubuntuhandbook.org/index.php/2019/03/display-cpu-memory-network-usage-in-ubuntu-18-04-panel/)

# Temperature
* `sensors`: Show all the sensors status

# Stress

* Emulate stress status
  - CPU: `stress --cpu N`
  - Memory(2 workers alloc/free 1GB): `stress --vm 2 --vm-bytes 1G`
  - IO: `stress --io N`
* Crash kernel manually
  - `sudo sh -c "echo c > /proc/sysrq-trigger"`

# Device

* Show "Device is busy" while umount
  -  `fuser -m <folder_name>` will show which processes use the folder.

## Peripheral Device

* List device info
  - Hardware: `lshw`
  - CPU: `lscpu`
  - USB: `lsusb` (The ID is in `/usr/share/misc/usb.ids`)
  - PCI: `lspci` (The ID is in `/usr/share/misc/pci.ids`)
  - Block devices: `lsblk`
  - Memory: `lsmem`

## graphic

* mesa-utils:
  - Show whether the system support "direct rendering"
    - `glxinfo | grep "direct rendering"`
  - Test FPS of the graphic
    - `glxgears`
* read-edid:
  - Read edid of display equipment
    - `sudo get-edid | parse-edid`

# Time

* Update system time with NTP
  - `ntpdate <NTP Server>`
  - `ntpdate time.stdtime.gov.tw`
* System time
  - `timedatectl`: Show system and RTC time
  - `sudo systemctl restart systemd-timesyncd.service`: Restart the service and synchronize the time
    * If you don't want to use NTP, restarting the SNTP service is a good way.
  - `timedatectl list-timezones`: List the timezone
  - `timedatectl set-timezone Asia/Taipei`: Set the timezone
* Save local time into RTC (If you use Windows and Linux in the same machine, it's necessary for time sync)
  - `sudo hwclock --localtime --systohc`

# Others

* Change default program (editor...)
  - `update-alternatives --display <COMMAND>`: List all candidates for certain command.
  - `sudo update-alternatives --config <COMMAND>`: Select which program we use in default.
  - `update-alternatives --install <LINK> <NAME> <PATH> <PRIORITY>`: Add option for certain command.
    * LINK: command absolute directory
    * NAME: command
    * PATH: real program absolute directory
    * PRIORITY
    * e.g. `update-alternatives --install /usr/bin/vim vim /usr/bin/vim.basic 1000`
  - `update-alternatives --remove <NAME> <PATH>`: Remove option for certain command.
* Change directory history
  - `pushd <directory>`: Push the current directory.
  - `dirs -p -v`: Show directory stack.
  - `dirs -c`: Clear directory stack.
  - `popd`: Pop the latest directory.
  - `pushd +N`: Choose the directory.
* Hostname
  - `hostnamectl`: Show hostname
  - `hostnamectl set-hostname [new hostname]`: Modify new hostname
* Show power status
  - `upower -d`
* View ACPI event(Volume up/down, power button)
  - `acpi_listen`
