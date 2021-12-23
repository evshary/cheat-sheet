# What is udev

udev is the device manager of Linux, which will handle all the userspace actions while adding/removing hardware.

While kernel starts to run, devtmpfs will create device node. 
udev can receive uevent from sysfs, which is netlink message.
Then load kernel module (according to `/lib/modules/<kernel>/modules.alias`), manage device node privilege, and create corresponding symlink file.

Refer to [Does udev load kernel modules?](https://unix.stackexchange.com/questions/392113/does-udev-load-kernel-modules)

# udevadm

udevadm is a udev management tool to monitor and control udev.

# Usage

* Show the service status of udev: `systemctl | grep udev`
* Monitor udev event
```bash
udevadm monitor
# Also show environment variables
udevadm monitor --env
```
* Get the ID of device
```bash
udevadm info /dev/<device_name>
# Get all the info of device
udevadm info -a /dev/<device_name>
```

# Example

Here gives an example how to map USB device to static name.

1. Plug the USB device and use `lsblk` to get the device name.

2. Get the info of device by device name.

```
udevadm info --query=property /dev/<device_name>
```

3. Add a new file under `/etc/udev/rules.d/`.
  - The info should be filled from udevadm command.
  - The below is an example file: "70-usb.rules"

```
ENV{DEVTYPE}=="partition",ENV{ID_VENDOR}="ADATA",ACTION=="add",SYMLINK+="usb%n"
```

4. Replug the USB device and you will see the symbol `/dev/usbn`.

# Tips

* Show how many uevent events are generated: `cat /sys/kernel/uevent_seqnum`

# Reference

* [udev - Linux dynamic device management](https://wiki.debian.org/udev)
* [Writing udev rules](http://reactivated.net/writing_udev_rules.html)
* [udev](https://www.freedesktop.org/software/systemd/man/udev.html)
