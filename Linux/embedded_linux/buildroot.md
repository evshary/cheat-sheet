# Buildroot

You can use buildroot to build your embedded Linux easily.

It'll create your own toolchain, bootloader, kernel and rootfs.

# Usage

* Get the code

```bash
git clone git://git.buildroot.net/buildroot
cd buildroot
git checkout 2021.11-rc3
```

* Build
  - The build result will be under `output`

```bash
make qemu_arm_versatile_defconfig
make
```

* Run
  - More information will be under `board/qemu/arm-versatile/readme.txt`

```bash
qemu-system-arm -M versatilepb -kernel output/images/zImage -dtb output/images/versatile-pb.dtb -drive file=output/images/rootfs.ext2,if=scsi,format=raw -append "rootwait root=/dev/sda console=ttyAMA0,115200" -serial stdio -net nic,model=rtl8139 -net user # qemu_arm_versatile_defconfig
```

# Reference

* [buildRoot study - 建立自己的作業系統](http://fichugh.blogspot.com/2016/02/buildroot-study.html)
* [raspberry_mp3](https://hugh712.gitbooks.io/raspberry_mp3/content/)
* [Buildroot架構解析](https://hugh712.gitbooks.io/buildroot/content/)
