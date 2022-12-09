# perf
## Installation
```
# Check perf option is enable in kernel or not
cat "/boot/config-`uname -r`" | grep "PERF_EVENT"
# Install perf
sudo apt install linux-tools-common
# You can run perf list and it'll show which version you should install
sudo apt install linux-tools-<version>-generic
# If you want to monitor cache miss
sudo sh -c " echo 0 > /proc/sys/kernel/kptr_restrict"
```
## Usage
* List event
  - `sudo perf list`: List all available events
* Track process
  - `sudo perf top -p <PID>`: Show the time usage of certain process
* Get statistics
  - `sudo perf stat <executable>`: Show the statistics of certain executable
  - `sudo perf stat -r 5 -e cache-misses <executable>`: Only monitor cache-misses and repeat 5 times
    - `-e <event>`: You can select which event you want to monitor
    - `-r <repeat times>`: Repeat times
* Record and show result
  - `sudo perf record -F 50000 -g -e cpu-clock <executable>`: Test and record result into perf.data
    - `-F <freq>`: Increase the sampling frequency
    - `-g`: Add calling graph
    - `-e <event>`: Record events
  - `sudo perf report`: read perf.data and show the result.

## Using FlameGraph
* Clone FlameGraph
```
git clone https://github.com/brendangregg/FlameGraph.git
```
* Record
```
sudo perf record -e cpu-clock -g <executable>
```
* Parse with script
```
sudo perf script -i perf.data &> perf.unfold
```
* Generate svg
```
sudo ./FlameGraph/stackcollapse-perf.pl perf.unfold &> perf.folded
sudo ./FlameGraph/flamegraph.pl perf.folded > perf.svg
```

# Memory usage

* Use pidstat: `sudo apt install sysstat`

* Trace the memory of the executable

```shell
pidstat -C <executable_name> -r
```
