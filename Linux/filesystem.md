# Layout

![image](https://user-images.githubusercontent.com/456210/150629562-5c87e08a-8de8-4bd4-927b-49354d279b0d.png)
[Image Src](https://joerismissaert.dev/managing-storage-understanding-mbr-and-gpt-partitions/)

# File system type

* FAT: Used by DOS. Follow 8.3 rules and not support 4G file.
* VFAT: Solve the issue of FAT.
* NTFS: Windows file system format
* EXT2/EXT3/EXT4: Linux file system format
* NFS: Network file system
* SMB/CIFS: Used by Samba

# Disk

* List all available disk (No matter disk is mount or not)
  - `lsblk`
* Clear disk
  - `dd if=/dev/zero of=/dev/sda bs=1M status=progress`
* Show partition information
  - `sudo dumpe2fs -h /dev/sda0`
* Show the list of disks
  - `sudo fdisk -l`
* Create/delete partiion for the disk
  - `sudo fdisk /dev/nvme0n1p1`
* Test read/write of the disk
  - `sudo hdparm -Tt /dev/sda0`
* Format the disk (`mkfs.<ext>`)
  - `sudo mkfs.fat /dev/sda`
* Reload partition
  - `partprobe`
* List the disk (Only disk is mount): `df -h`
  - Also show filesystem type: `df -hT`
* Mount/Unmount the device:
  - `mount <device> <mount point>`
  - `umount <device>` or `umount <mount point>`
  - e.g. `mount /dev/nvme0n1p1 /mnt`

## NVME

If you use NVME device, you'll see three devices: `/dev/nvme0`, `/dev/nvme0n1`, `/dev/nvme0n1p1`

* `/dev/nvme0` means NVME device controller
* `/dev/nvme0n1` means NVME storage namespaces: the devices you use for actual storage
  - You can format the disk by operating this device
* `/dev/nvme0n1p1`: means the partition in NVME

Reference: [Why is there both character device and block device for nvme?](https://serverfault.com/questions/892134/why-is-there-both-character-device-and-block-device-for-nvme)

# chroot

* Before chroot, mount necessary folder

```bash
cd <your_rootfs_path>
sudo mount --bind /proc proc/
sudo mount --bind /sys sys/
sudo mount --bind /dev dev/
sudo mount --bind /dev/pts dev/pts
```

* chroot

```
sudo chroot . /bin/bash
```

* After chroot

```bash
sudo umount dev/pts
sudo umount dev
sudo umount proc
sudo umount sys
```
