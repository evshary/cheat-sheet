# Example driver

This is really simple driver.
It'll create `/dev/dummy0` to `/dev/dummy3` and `/sys/class/dummy`.

# Build

```bash
# clean
make clean
# Build
make
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

# Create node by yourself

In the example, the driver creates `/sys/class/dummy` automatically.
In fact, you can also create the device node by yourself by using mknod.

```bash
# Define CREATE_CLASS to 0
make clean
make
# Create the device node
mknod /dev/dummy c 42 0
# insert & remove module
insmod dummy.ko
rmmod dummy
```