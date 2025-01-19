# Debug

List some debug methods

## Address Sanitizer

ASan will insert stub into functions like malloc / free.

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

Valgrind transforms the binary into IR and runs it in VM, so it's slow.

```shell
# Installation
sudo apt install valgrind
# Build
make valgrind
# Test memory leak
valgrind --leak-check=full --log-file=valgrind.log ./memory_leak.out
```

### Reference

* [以 Valgrind 分析記憶體問題](https://hackmd.io/@sysprog/linux2023-lab0/%2F%40sysprog%2Flinux2023-lab0-b#%E4%BB%A5-Valgrind-%E5%88%86%E6%9E%90%E8%A8%98%E6%86%B6%E9%AB%94%E5%95%8F%E9%A1%8C)
