# How to rebuild kernel

1. Get the kernel you want from [here](https://cdn.kernel.org/pub/linux/kernel/).

```bash
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.9.8.tar.xz
tar Jxvf linux-5.9.8.tar.xz
```

2. Install necessary packages

```bash
sudo apt install kernel-package build-essential libncurses-dev bison flex libssl-dev libelf-dev dwarves
```

3. Copy the config file from current kernel. This make the configuration much more easier.

```bash
cd linux-5.9.8
cp -v /boot/config-$(uname -r) .config
```

4. Adjust the config.

```bash
make menuconfig
```

5. Create Debian package.

```bash
make -j $(nproc) deb-pkg
```

6. Install kernel and header

```bash
cd ..
sudo dpkg -i ./linux-headers-5.9.8_5.9.8-1_amd64.deb ./linux-image-5.9.8_5.9.8-1_amd64.deb
```

7. Modify GRUB if you want to change the kernel manually.

```bash
$ sudo vi /etc/default/grub

...
GRUB_DEFAULT=0
#GRUB_TIMEOUT_STYLE=hidden
GRUB_TIMEOUT=5
...

$ sudo update-grub
```

8. If you want to uninstall

```bash
sudo apt remove linux-headers-5.9.8 linux-image-5.9.8
```

9. Optional: if you don't want to use deb to install, you can run traditional build. (Replace 5, 6)

```bash
make -j $(nproc)
# Install kernel modules
sudo make modules_install
# Install Linux kernel 
sudo make install
```

# Tips
* Check kernel version from source code

```bash
make kernelversion
# You can also view version from Makefile directly.
```

* Check the config of the current kernel: `cat /boot/config-$(uname -r)`

* Only build one kernel module module
  - Refer to https://askubuntu.com/a/168293

```bash
make drivers/net/usb/lan78xx.ko
# Remount the module (Or you can copy to `/usr/lib/modules/`uname -r`/kernel/drivers/net/usb/`)
sudo modprobe -r lan78xx
sudo insmod ./lan78xx.ko
```

# Common Error
## Creating deb packages
* If there is link file in the kernel folder, it'll fail while creating deb packages. (For example, vmlinux-gdb.py)
  - Solution: delete link file.
* dpkg-source: error: cannot represent change to .config.swp: binary file contents changed
  - Solution: Make sure you don't open any files in the kernel
* dpkg-source: error: orig directory 'linux-5.10.92.orig' already exists, not overwriting, giving up;
  - Solution: Remove unsed folder and packages created while creating deb packages
* If you want to recreate deb file, need to remove the following files
  - link file, e.g. vmlinux-gdb.py
  - file / folder created while creating deb packages, e.g. linux-5.10.92.orig
  - debian folder

## Build kernel
* No rule to make target 'debian/canonical-certs.pem', needed by 'certs/x509_certificate_list'
  - Solution: modify `.config`, and empty `CONFIG_SYSTEM_TRUSTED_KEYS` and `CONFIG_SYSTEM_REVOCATION_KEYS`
* BTF: .tmp_vmlinux.btf: pahole (pahole) is not available
  - Solution: `sudo apt install dwarves` or modify `CONFIG_DEBUG_INFO_BTF=n` in `.config`

# cmdline

* We can pass parameters to kernel with cmdline
  - refer to [cmdline](https://www.kernel.org/doc/html/latest/admin-guide/kernel-parameters.html)
