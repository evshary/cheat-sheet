# Device Tree

* Install packages

```bash
sudo apt-get install device-tree-compiler
```

* How to modify model name in device tree
  - Back your device tree first

```bash
# Backup
sudo cp /boot/device_tree_name.dtb /boot/device_tree_name_bak.dtb
# Dump device tree
sudo fdtdump /boot/device_tree_name.dtb
# Get property
sudo fdtget /boot/device_tree_name.dtb / model
# Set property
sudo fdtput -t s /boot/device_tree_name.dtb / model "New model name"
```

* Modify extlinux.conf and add FDT. Make sure the image boot with this device tree.

```bash
sudo vi /boot/extlinux/extlinux.conf
LABEL primary
      MENU LABEL primary kernel
      LINUX /boot/Image
      FDT /boot/tegra194-p2888-0001-p2822-0000-maxn-6cam.dtb
      INITRD /boot/initrd
      APPEND ${cbootargs} quiet
```

# Reference
* [linux设备树笔记--dts基本概念及语法](https://e-mailky.github.io/2016-12-06-dts-introduce): Basic device tree syntax.
