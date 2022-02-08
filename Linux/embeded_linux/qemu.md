# qemu

Hardware simulation tools.

# Installation

```bash
# Ubuntu
sudo apt install qemu-system-arm
# gentoo
QEMU_SOFTMMU_TARGETS="arm i386 x86_64" QEMU_USER_TARGETS="arm i386 x86_64" emerge qemu
# mac
brew install qemu
```

# Usage

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

# ARM simulation

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
