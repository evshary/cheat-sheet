# What is udev

udev is the device manager of Linux, which will handle all the userspace actions while adding/removing hardware.
udev can receive uevent from sysfs, which is netlink message.

# udevadm

udevadm is a udev management tool to monitor and control udev.

* Show the service status of udev: `systemctl | grep udev`
* Monitor udev event: `udevadm monitor`
* Get the ID of device: `udevadm info /dev/<device_name>`
* Get all the info of device: `udevadm info -a /dev/<device_name>`

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

# Reference
* [udev - Linux dynamic device management](https://wiki.debian.org/udev)
* [Writing udev rules](http://reactivated.net/writing_udev_rules.html)
* [udev](https://www.freedesktop.org/software/systemd/man/udev.html)