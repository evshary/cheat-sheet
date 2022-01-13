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
