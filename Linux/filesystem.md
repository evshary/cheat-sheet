# File System

## Bootup Layout

![image](https://user-images.githubusercontent.com/456210/150629562-5c87e08a-8de8-4bd4-927b-49354d279b0d.png)

[Image Src](https://joerismissaert.dev/managing-storage-understanding-mbr-and-gpt-partitions/)

## File system type

* FAT: Used by DOS. Follow 8.3 rules and not support 4G file.
* VFAT: Solve the issue of FAT.
* NTFS: Windows file system format
* EXT2/EXT3/EXT4: Linux file system format
* NFS: Network file system
* SMB/CIFS: Used by Samba

### NVME

If you use NVME device, you'll see three devices: `/dev/nvme0`, `/dev/nvme0n1`, `/dev/nvme0n1p1`

* `/dev/nvme0` means NVME device controller
* `/dev/nvme0n1` means NVME storage namespaces: the devices you use for actual storage
  * You can format the disk by operating this device
* `/dev/nvme0n1p1`: means the partition in NVME

Reference: [Why is there both character device and block device for nvme?](https://serverfault.com/questions/892134/why-is-there-both-character-device-and-block-device-for-nvme)

## Commands

### Disk

* List all available disk (No matter disk is mount or not)
  * `lsblk`
* Clear disk
  * `dd if=/dev/zero of=/dev/sda bs=1M status=progress`
* Show partition information
  * `sudo dumpe2fs -h /dev/sda0`
* Show the list of disks
  * `sudo fdisk -l`
* Create/delete partiion for the disk
  * `sudo fdisk /dev/nvme0n1p1`
* Test read/write of the disk
  * `sudo hdparm -Tt /dev/sda0`
* Format the disk (`mkfs.<ext>`)
  * `sudo mkfs.fat /dev/sda`
  * `sudo mkfs.ext4 /dev/sda`
* Reload partition
  * `partprobe`
* List the disk (Only disk is mount): `df -h`
  * Also show filesystem type: `df -hT`
* Mount/Unmount the device:
  * `mount <device> <mount point>`
  * `umount <device>` or `umount <mount point>`
  * e.g. `mount /dev/nvme0n1p1 /mnt`
* Check disk health

```shell
sudo apt install smartmontools
# Run self-test
sudo smartctl -t short /dev/sda
# Get result
sudo smartctl -H /dev/sda
# Detail overall status
sudo smartctl -a /dev/sda
```

### chroot

* Before chroot, mount necessary folder

```shell
cd <your_rootfs_path>
sudo mount --bind /proc proc/
sudo mount --bind /sys sys/
sudo mount --bind /dev dev/
sudo mount --bind /dev/pts dev/pts
```

* chroot

```shell
sudo chroot . /bin/bash
```

* After chroot

```shell
sudo umount dev/pts
sudo umount dev
sudo umount proc
sudo umount sys
```

### swap

* Check the current swap size

```shell
free -h
```

* Increase the swap size

```shell
# Remove the current swapfile
sudo swapoff /swapfile
sudo rm /swapfile

# Create a new swapfile
sudo fallocate -l 32G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
```

### Loop

Loop is a block device and able to load file (iso, img...).
The name is like `/dev/loopX`.

```shell
# Create a dummy file
dd if=/dev/zero of=disk.img bs=1M count=100
# Load the file to loop device
losetup /dev/loop0 disk.img
# Format the device
mkfs.ext4 /dev/loop0
# Mount the device to a directory
mount /dev/loop0 /mnt
# Do some reads/writes
# Umount
umount /mnt
# Release the loop device
losetup -d /dev/loop0
```
