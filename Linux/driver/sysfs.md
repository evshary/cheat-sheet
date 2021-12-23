# sysfs

sysfs is the virtual filesystem in RAM.
The folder under `/sys` means different aspects of the devices connected to the system now.

* `/sys/bus`: Classified by bus. (kernel structure: struct device)
* `/sys/class`: Classified by the device function (kernel structure: struct class)
* `/sys/device`: Classified by physical devices (kernel structure: struct device)

For more detail, refer to [sysfs、udev 和 它们背后的 Linux 统一设备模型](https://www.binss.me/blog/sysfs-udev-and-Linux-Unified-Device-Model/)

# The difference between sysfs and /dev

The sysfs and /dev can both control devices, but sysfs has more advantages:

1. Able to have fine-grained permission settings
2. Able to control device with easier way (echo / cat). /dev needs to use ioctl.

Refer to [sysfs and devtmpfs](https://unix.stackexchange.com/questions/236533/sysfs-and-devtmpfs)
