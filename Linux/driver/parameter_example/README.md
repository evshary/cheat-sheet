# Example driver

The example tells you how to pass user's parameters to the driver.

# Build

```bash
make
# clean
make clean
```

# Test

```bash
# insert module with parameters
insmod dummy.ko my_param=123
# remove module
rmmod dummy
```
