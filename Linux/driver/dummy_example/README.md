# Example driver

This is really simple driver.
It'll create /dev/dummy0 to /dev/dummy3 and /sys/class/dummy.

# Build

```bash
make
# clean
make clean
```

# Test

```bash
# insert module
insmod dummy.ko
# Try to use module
echo test > /dev/dummy0
# remove module
rmmod dummy
```
