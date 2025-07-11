# LTTng

## Installation

```shell
sudo apt install lttng-tools lttng-modules-dkms babeltrace liblttng-ust-dev
```

## Usage

* Switch to root if you want to observe kernel events

* Create session
  * Store trace under the `~/lttng-traces/`

```shell
lttng create mysession
```

* Enable events

```shell
# List all kernel events
lttng list -k
# List all user events
lttng list -u
# Enable context switch events
lttng enable-event -k sched_switch
```

* Start/stop tracing

```shell
# Start
lttng start
# You can run your program or execute a command that can trigger context switch
sleep 1
# Stop
lttng stop
```

* Destroy the session

```shell
lttng destroy
```

* Check the trace result

```shell
babeltrace ~/lttng-traces/mysession-*
```
