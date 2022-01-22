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

* Clear disk
  - `dd if=/dev/zero of=/dev/sda bs=1M status=progress`
* Show partition information
  - `sudo dumpe2fs -h /dev/sda0`
* Show the list of disks
  - `sudo fdisk -l`
* Test read/write of the disk
  - `sudo hdparm -Tt /dev/sda0`
* Format the disk (`mkfs.<ext>`)
  - `sudo mkfs.fat /dev/sda`
* Reload partition
  - `partprobe`
* List the disk: `df -h`
  - Also show filesystem type: `df -hT`


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
