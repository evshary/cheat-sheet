# Performance Tool

## CPU Usage

* [perf](perf.md)
* [LTTng](LTTng.md)

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
