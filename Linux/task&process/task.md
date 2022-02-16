# Task Priority

## introduction

The total number of priorities is 140

- realtime range: 0-99
- user space priority range: 100-139

For user space priority, there can be represented as two values: Nice(NI) and Priority(PR or PRI).

- Actual priority: 100-139
- NI: -20-19
- PR: 0-39

So you can know that: PR = 20 + NI

## Adjust priority

* Run command with specific priority.
  - if you want negative value, need root privilege.

```bash
# nice -n [nice-value] [commands]
nice -n -20 ./your_application
```

* Adjust the priority

```bash
# renice -n [nice-value] -p [PID]
renice -n -20 -p 1055
```

# CPU affinity

We can use taskset to view/set the relationship of tasks and CPU.

* Use HEX to assign CPU affinity.

```bash
# view which CPU the PID run on
taskset -p [PID]
# Set which CPU the PID can run
# For example, to run on core 0 and 4
# taskset -p 0x11 [PID]
taskset -p [MASK] [PID]
```

* Use human readable way to assign CPU affinity.

```bash
# view which CPU the PID run on
taskset -cp [PID]
# Set which CPU the PID can run
# For example, to run on core 0 and 4
# taskset -cp 0,4 [PID]
taskset -cp [core list] [PID]
```

* Use which CPU to run the task.

```bash
# Make sure the commands run on certain CPU core
# For example, to run application on core 0
# taskset 0x01 ./your_application
taskset [MASK] [commands]
```
