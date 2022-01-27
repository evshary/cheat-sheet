# qemu

## Usage

* qemu-img: `qemu-img create [-f format] filename size`
  - format: raw(default)、qcow、cow、vmdk、cloop

* qemu: `qemu [options] [disk_image]`
  - `-hda/-hdb file`: Use file as the image for IDE 0/1
  - `-hdc/-hdd file`: Use file as the image for IDE 2/3
  - `-cdrom file`: Use file as the image fro IDE CD-ROM (Unable to use -hdc)
  - `-cdrom /dev/hdX`: Use the real CD as IDE CD-ROM
  - `-boot [a|c|d]`: Boot from floppy(a), hard disk(c), CD(d)
  - `-m memorysize`: How much memory we use (default: 128MB)
  - `-M architecture`: Specify architecture
  - `-append "kernel options go here"`: Add kernel cmdline
  - `-drive option[,option[,option[,...]]]`: Define newdrive
    - `if=interface`：The interface to connect to drive, e.g. ide, scsi, sd, mtd, floppy, pflash, virtio
    - `file=file`：Use file as disk image
  - `-nographic`: no GUI
  - `-curses`: use curses
  - `-serial stdio`: show serial message on stdio

* QEMU hotkey
  - ctrl + alt + G: Exit the window
  - ctrl + a + c：toggle between the guest system console and HMI console.
  - ctrl + a + x：immediately kill the QEMU instance.

## ARM simulation

### Installation
```bash
# Ubuntu
sudo apt install qemu-system-arm
# gentoo
QEMU_SOFTMMU_TARGETS="arm i386 x86_64" QEMU_USER_TARGETS="arm i386 x86_64" emerge qemu
# mac
brew install qemu
```

### Usage

Use Debian distribution

Since ARM doesn't have BIOS, it can not init disk and read the first sector on disk.
We need to use `-initrd` to load kernel and `-kernel` to specify which kernel we want to use.

```bash
# Create image
qemu-img create -f raw hda.img 3G
# Download initrd and linux
wget http://archive.debian.org/debian/dists/wheezy/main/installer-armhf/current/images/vexpress/netboot/initrd.gz
wget http://archive.debian.org/debian/dists/wheezy/main/installer-armhf/current/images/vexpress/netboot/vmlinuz-3.2.0-4-vexpress
# Install OS
qemu-system-arm -M vexpress-a9 -kernel vmlinuz-3.2.0-4-vexpress -initrd initrd.gz -append "root=/dev/mmcblk0" -drive if=sd,cache=unsafe,file=hda.img
# Extract the initrd in img, then qemu can use initrd to start kernel
# If you run "file hda.img", it'll show startsector 2048, so the offset will be 512*2048
mkdir mountdir
mount -o loop,offset=$((512*2048)) hda.img mountdir/
cp mountdir/initrd.img-3.2.0-4-vexpress .
umount mountdir/
# Run Linux
qemu-system-arm -M vexpress-a9 -kernel vmlinuz-3.2.0-4-vexpress -initrd initrd.img-3.2.0-4-vexpress -append "root=/dev/mmcblk0p2" -drive if=sd,cache=unsafe,file=hda.img
# Run Linux with network
# Map port 6666 on host to port 8080 on guest
qemu-system-arm -M vexpress-a9 -kernel vmlinuz-3.2.0-4-vexpress -initrd initrd.img-3.2.0-4-vexpress -append "root=/dev/mmcblk0p2" -drive if=sd,cache=unsafe,file=hda.img -nic user,hostfwd=tcp::6666-:8080
# Set your IP in qemu
ifconfig eth0 10.0.2.15 netmask 255.255.255.0
# You can use "nographic" to disable GUI and show console on ttyAMA0
qemu-system-arm -M vexpress-a9 -kernel vmlinuz-3.2.0-4-vexpress -initrd initrd.img-3.2.0-4-vexpress -append "root=/dev/mmcblk0p2 console=ttyAMA0" -drive if=sd,cache=unsafe,file=hda.img -nic user,hostfwd=tcp::6666-:8080 -nographic
```

There are some ways we don't need to install by ourselves

* Root：root / root
* User：user / user

```bash
# Download files from https://people.debian.org/~aurel32/qemu/armel/
qemu-system-arm -M versatilepb -kernel vmlinuz-2.6.32-5-versatile -initrd initrd.img-2.6.32-5-versatile -hda debian_squeeze_armel_standard.qcow2 -append "root=/dev/sda1"
qemu-system-arm -M versatilepb -kernel vmlinuz-2.6.32-5-versatile -initrd initrd.img-2.6.32-5-versatile -hda debian_squeeze_armel_desktop.qcow2 -append "root=/dev/sda1"
qemu-system-arm -M versatilepb -kernel vmlinuz-3.2.0-4-versatile -initrd initrd.img-3.2.0-4-versatile -hda debian_wheezy_armel_standard.qcow2 -append "root=/dev/sda1"
qemu-system-arm -M versatilepb -kernel vmlinuz-3.2.0-4-versatile -initrd initrd.img-3.2.0-4-versatile -hda debian_wheezy_armel_desktop.qcow2 -append "root=/dev/sda1"
```

Build from Linux source code

```bash
# Download your toolchain (cross compiler first)
# Download kernel source code: Here we use Linux 3.18.11
make ARCH=arm vexpress_defconfig # Use vexpress settings
make ARCH=arm menuconfig
# Note that "General setup-->Cross-compiler tool prefix" should be arm-linux-gnueabi-
make ARCH=arm
# You can specify CROSS_COMPILE instead of modifying .config
make ARCH=arm CROSS_COMPILE=armv6j-hardfloat-linux-gnueabi-
# zImage will be under arch/arm/boot

# Test
armv6j-hardfloat-linux-gnueabi-gcc -static init.c -o init
echo init|cpio -o --format=newc > initramfs
# Run
qemu-system-arm -M vexpress-a9 -kernel zImage -initrd initramfs -serial stdio -append "console=tty1"

# Use busybox to create file system
# Download from http://busybox.net/
make ARCH=arm menuconfig
# Go to "Busybox Settings->Build Options" and check "Build BusyBox as a static binary", then we don't need to copy library by ourselves
make ARCH=arm CROSS_COMPILE=armv6j-hardfloat-linux-gnueabi-
make install CROSS_COMPILE=armv6j-hardfloat-linux-gnueabi-
# _install folder will be created
# Modify linuxrc
mv linuxrc init
# Add new folder
mkdir dev etc lib opt proc sys tmp var
# Copy cross compiler library (If you use static binary, ignore this step)
cp /usr/armv6j-hardfloat-linux-gnueabi/lib/* lib

# Add /etc/init.d/rcS
#!/bin/sh
mount -t proc none /proc
mount -t sysfs none /sys
# Generate node file needed by drivers
/sbin/mdev -s

# Modify privilege
chmod +x rcS

# Create root file system
cd _install
find . | cpio -H newc -o > ../initrd
gzip ../initrd
qemu-system-arm -M vexpress-a9 -kernel zImage -initrd initrd.gz -append "console=tty1"
# If you want to run on terminal use "-serial stdio" to show serial message on stdio and pass kernel message to ttyAMA0
qemu-system-arm -M vexpress-a9 -kernel zImage -initrd initrd.gz -serial stdio -append "console=ttyAMA0"
```

Refer to [here]](https://balau82.wordpress.com/2012/03/31/compile-linux-kernel-3-2-for-arm-and-emulate-with-qemu/)


# Create toolchain

## Gentoo

### How to use crossdev
* -t means target, format: CPU-HW-OS-Clib
  - CPU architecture：alpha, arm, i386, x86_64...
  - Hardware Platform / Vendor：pc, unknown...
  - Operating System：linux, elf, uclinux...
  - C Library：eabi, gnu, gnueabi, uclibc
  - EX: i686-pc-linux-gnu, x86_64-pc-linux-gnu, armv7a-hardfloat-linux-gnueabi, arm-unknown-linux-gnu
* -S：Use stable
* -v：verbose

You can also define with more detail.

```bash
USE="-*" crossdev -p -v \
--binutils 2.16.92 \
--gcc 3.4.6-r1 \
--kernel 2.6.11-r4 \
--libc 0.9.28 \
--ex-gdb \
--target powerpc-softfloat-linux-uclibc
```
* Use crossdev to create cross compile
```bash
# install crossdev
emerge crossdev
# Add the following line in /etc/portage/make.conf
PORTDIR_OVERLAY=/usr/local/portage
# Use crossdev to install cross compiler
crossdev -S -v -t armv6j-hardfloat-linux-gnueabi
# To remove cross compiler
crossdev -C armv6j-hardfloat-linux-gnueabi
# After a long time installation, you can use gcc-config to control
# list toolchain you have now
gcc-config -l
# decide which toolchain you use
gcc-config x86_64-pc-linux-gnu-4.8.3
source /etc/profile
# Build
armv6j-hardfloat-linux-gnueabi-gcc --static test.c -o test
# Execution
qemu-arm test
# If you don't build wite static link， use -L to add library path
qemu-arm -L /usr/armv6j-hardfloat-linux-gnueabi/ abc
```

## Ubuntu

```bash
# Installation
sudo apt install gcc-arm-linux-gnueabi
# Build
arm-linux-gnueabi-gcc --static test.c -o test
# Execution
qemu-arm-static test
# You need to link library, you don't build with static link (-L means library path)
qemu-arm-static -L /usr/arm-linux-gnueabi/ test
```

## Reference

* [Crossdev](http://gentoo-en.vfose.ru/wiki/Crossdev)
* [Gentoo Cross Development Guide](https://wwwold.gentoo.org/proj/en/base/embedded/cross-development.xml)
