# Debug

List some debug methods

## GDB

![image](https://github.com/user-attachments/assets/be43828c-0309-4b53-a27e-ffc65d8cf1ef)

[image source](https://aosabook.org/en/v2/gdb.html)

Disable the resource control first: `ulimit -c unlimited`

Get the core dump:

* Native host
  * The coredump can be found here `/var/lib/apport/coredump`
* Docker
  1. Run docker in privileged mode:
  2. Assign the path to sore coredump: `echo "/tmp/core.%e.%p.%h.%t" > /proc/sys/kernel/core_pattern`

After getting the coredump:

1. Use gdb to analyze: `gdb ./executable /tmp/core.xxx`
2. Run `bt` to get backtrace

If debugging multithreaded

* `info threads`: List all threads
* `thread <id>`: Switch thread
* `bt` or `thread apply all bt`: Check backtrace

GUI version: cgdb

```shell
sudo apt install cgdb
sudo cgdb -- -p <PID>
```

## Address Sanitizer

ASan will insert stub into functions like malloc / free in the compile time.

```shell
# Enable address sanitizer
make asan
# Run test
./memory_leak.out
# Don't stop and export log to asan.log
ASAN_OPTIONS=halt_on_error=0:log_path=asan.log ./memory_leak.out
```

## Undefined Behavior Sanitizer

UBSan can help us detect the undefined behavior.

```shell
# Enable undefined sanitizer
make ubsan
# Run test
./int_overflow.out
# Stop if UB is detected, export log to ubsan.log, and print stack trace
UBSAN_OPTIONS=halt_on_error=1:log_path=ubsan.log:print_stacktrace=1 ./int_overflow.out
```

### Reference

* [AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer)

## Valgrind

Valgrind transforms the binary into IR and runs it in VM, so it's slow but precise.

```shell
# Installation
sudo apt install valgrind
# Build
make valgrind
# Test memory leak
valgrind --leak-check=full --log-file=valgrind.log ./memory_leak.out
```

## heaptrack

Use `LD_PRELOAD` to replace malloc and free function, so don't need to recompile.

```shell
# Installation
sudo apt install heaptrack heaptrack-gui
# Build
make heaptrack
# Test memory leak
heaptrack ./memory_leak.out
# Show GUI
heaptrack_gui heaptrack.memory_leak.out.*.zst
```

### Reference

* [以 Valgrind 分析記憶體問題](https://hackmd.io/@sysprog/linux2023-lab0/%2F%40sysprog%2Flinux2023-lab0-b#%E4%BB%A5-Valgrind-%E5%88%86%E6%9E%90%E8%A8%98%E6%86%B6%E9%AB%94%E5%95%8F%E9%A1%8C)
