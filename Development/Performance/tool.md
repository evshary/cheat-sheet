# Performance Tool

## samply

[Samply](https://github.com/mstange/samply) is an better version of flamegraph.

* Install simply: `cargo install --locked samply`
* If you're using in Rust project
  * Create a global cargo profile: `~/.cargo/config.toml`
    ```toml
    [profile.profiling]
    inherits = "release"
    debug = true
    ```
  * Build with the profile: `cargo build --profile profiling`
* Grant access to performance events system
  ```
  echo '1' | sudo tee /proc/sys/kernel/perf_event_paranoid
  ```
* Record: `samply record ./my-application my-arguments` or `samply record ./target/profiling/yourrustprogram`
* Upload the file to [the firefox profiler](https://profiler.firefox.com/)

## perf

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
    * `-g`: Add calling graph
    * `-e <event>`: Record events
  * `sudo perf report`: read perf.data and show the result.

### Using FlameGraph

* Clone FlameGraph

```shell
git clone https://github.com/brendangregg/FlameGraph.git
```

* Record

```shell
sudo perf record -e cpu-clock -g <executable>
```

* Parse with script

```shell
sudo perf script -i perf.data &> perf.unfold
```

* Generate svg

```shell
sudo ./FlameGraph/stackcollapse-perf.pl perf.unfold &> perf.folded
sudo ./FlameGraph/flamegraph.pl perf.folded > perf.svg
```

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
