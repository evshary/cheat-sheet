# Performance Tool

## perf

* `perf_events` is a subsystem inside the Linux kernel to collect different kinds of events.
* `perf` is a user-space tool to coordinate with `perf_events`.

![image](https://github.com/user-attachments/assets/9e8f14d7-b7a4-4107-af70-f40b0a91de02)

From [深入探索 perf CPU Profiling 实现原理](https://mazhen.tech/p/%E6%B7%B1%E5%85%A5%E6%8E%A2%E7%B4%A2-perf-cpu-profiling-%E5%AE%9E%E7%8E%B0%E5%8E%9F%E7%90%86/)

`cpu-clock` event is to trace the cycle of CPU.
We can use this to trigger sampling the current running function.
Then we will know which function takes more time.

![image](https://github.com/user-attachments/assets/5524ec46-b39d-4f16-8e1a-99d189a55150)

From [一文看懂 Linux 性能分析｜perf原理（超详细~）](https://zhuanlan.zhihu.com/p/573633261)

### Installation

```shell
# Check perf option is enable in kernel or not
cat "/boot/config-`uname -r`" | grep "PERF_EVENT"
# Install perf
sudo apt install linux-tools-common
# You can run perf list and it'll show which version you should install
sudo apt install linux-tools-<version>-generic
# If you want to monitor cache miss
sudo sh -c " echo 0 > /proc/sys/kernel/kptr_restrict"
```

### Usage

* List event
  * `sudo perf list`: List all available events
* Track process
  * `sudo perf top -p <PID>`: Show the time usage of certain process
* Get statistics
  * `sudo perf stat <executable>`: Show the statistics of certain executable
  * `sudo perf stat -r 5 -e cache-misses <executable>`: Only monitor cache-misses and repeat 5 times
    * `-e <event>`: You can select which event you want to monitor
    * `-r <repeat times>`: Repeat times
* Record and show result
  * `sudo perf record -F 50000 -g -e cpu-clock <executable>`: Test and record result into perf.data
    * `-F <freq>`: Increase the sampling frequency
    * `-g`: Add calling graph, equals to `--call-graph fp`
    * `--call-graph dwarf`: dwarf (debug information format) is more accurate than fp
    * `-e <event>`: Record events
  * `sudo perf report`: read perf.data and show the result.

### Using FlameGraph

* Clone FlameGraph

```shell
git clone https://github.com/brendangregg/FlameGraph.git
```

* Record

```shell
sudo perf record --call-graph dwarf <executable>
```

* Generate svg
  * You can ignore messages like `addr2line /root/.debug/.build-id/xx/xxxxxx/elf: could not read first record`

```shell
# Step by step
sudo perf script -i perf.data &> perf.unfold
sudo ./FlameGraph/stackcollapse-perf.pl perf.unfold &> perf.folded
sudo ./FlameGraph/flamegraph.pl perf.folded > perf.svg
# One line solution
sudo perf script | ./FlameGraph/stackcollapse-perf.pl | ./FlameGraph/flamegraph.pl > perf.svg
```

### FlameGraph (Rewrite in Rust)

* Installation

```shell
cargo install inferno
```

* Record

```shell
sudo perf record --call-graph dwarf <executable>
```

* Generate svg
  * You can ignore messages like `addr2line /root/.debug/.build-id/xx/xxxxxx/elf: could not read first record`

```shell
# Step by step
sudo perf script | inferno-collapse-perf > stacks.folded
cat stacks.folded | inferno-flamegraph > flamegraph.svg
# One line solution
sudo perf script | inferno-collapse-perf | inferno-flamegraph > flamegraph.svg
```

## samply

[Samply](https://github.com/mstange/samply) is an better version of flamegraph.

* Install simply: `cargo install --locked samply`
  * You can [install binaries](https://github.com/mstange/samply?tab=readme-ov-file#install-prebuilt-binaries-via-shell-script) if you can't build in your system.
* If you're using in Rust project
  * Create a global cargo profile: `~/.cargo/config.toml`

    ```toml
    [profile.profiling]
    inherits = "release"
    debug = true
    ```

  * Build with the profile: `cargo build --profile profiling`
* Grant access to performance events system

  ```shell
  echo '1'| sudo tee /proc/sys/kernel/perf_event_paranoid
  # You might need more permission if running inside the docker
  echo '-1' | sudo tee /proc/sys/kernel/perf_event_paranoid
  ```

* Record
  * `samply record ./my-application my-arguments`
  * `samply record ./target/profiling/yourrustprogram`
* Once the program stopped, we can access the result with `127.0.0.1:3000`
* If running the test on remote side, use port forward:
  * SSH command: `ssh -L 3000:localhost:3000 user@server.ip`
  * vscode remote ssh port forwarding
* Run the existing result: `samply load profile.json.gz -P 3000`
* If you want to share the result with others, you can choose "Upload Local Profile".

## Memory usage

* Use pidstat: `sudo apt install sysstat`

* Trace the memory of the executable

```shell
pidstat -C <executable_name> -r
```

## Network

* Throughput

```shell
# Run the server
iperf3 -s
# Run the client
iperf3 -c 127.0.0.1 -t 10 -i 1
```

* Latency

```shell
ping -c 100 127.0.0.1
```

## sar

Record the whole system resource usage.
It will record the system data on background after installation. (Under `/var/log/sysstat/sa.*`)

* Installation

```shell
sudo apt install sysstat
```

* Usage

```shell
# Record CPU (1 sample every sec, 3 samples)
sar -u 1 3
# Every CPU
sar -P ALL 1 3
# Memory
sar -r 1 3
# Disk
sar -d 1 3
# Network
sar -n DEV 1 3
```

* Log

```shell
# Read history log (today)
sar
# Read a specific log
sar -f /var/log/systat/sa*
# Write to a specific file
sar -o /tmp/my.log 60 10
```

## atop

Able to record the detailed resource usage of each process

* Installation

```shell
sudo apt install atop
```

* Interactive usage
  * `h`: help
  * `g`: General view
  * `m`: Memory view
  * `c`: Command view
  * `C`: Sort with CPU
  * `M`: Sort with memory
  * `z`: pause/resume

```shell
# interactive mode
atop
# Update every 5 seconds
atop 5
```

* Log mode

```shell
# Write log (1 sample every 60 second, 30 samples)
atop -w my.log 60 30

# Read log
#  t: next
#  T: back
#  b: specify time
atop -r ./my.log

# Summary
atopsar -A -r ./my.log
# Read log with a time range
atopsar -A -b 11:52:00 -e 11:52:03 -r ./my.log
```
