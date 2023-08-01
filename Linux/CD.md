# CD

# Transform CD into iso

After putting the CD into tray, CD will mount on `/dev/sr0`
`/dev/cdrom` will link to `/dev/sr0`

```shell
# Copy the CD
umount /dev/sr0
dd if=/dev/sr0 of=/tmp/mycd.iso
# Check the checksum
md5sum /dev/sr0
md5sum /tmp/mycd.iso
# Eject
eject
```

# Mount iso

```shell
# Mount
sudo mkdir /mnt/iso
sudo mount -o loop myisofile.iso /mnt/iso
# Check
mount
# Unmount
sudo umount /mnt/iso/
```
