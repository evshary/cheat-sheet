# How to rebuild kernel

1. Get the kernel you want from [here](https://cdn.kernel.org/pub/linux/kernel/).

```bash
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.9.8.tar.xz
tar Jxvf linux-5.9.8.tar.xz
```

2. Install necessary packages

```bash
sudo apt install kernel-package build-essential libncurses-dev bison flex libssl-dev libelf-dev
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
