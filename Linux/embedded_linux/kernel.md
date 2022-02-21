# Build Linux

* Get the code

```bash
git clone https://github.com/torvalds/linux.git
cd linux
git checkout v4.10
```

* According to your compiler

```bash
# Use the compiler generated by yourself
export CROSS_COMPILE=arm-unknown-linux-gnueabihf-
# Use the compiler from other vendors
export CROSS_COMPILE=arm-none-linux-gnueabi-
# Use the compiler from Ubuntu
export CROSS_COMPILE=arm-linux-gnueabi-
```

* Build
  
```bash
# 1. clean build files
#    clean(generated file) < mrproper(generated file + .config) < distclean (generated file + config + patch)
make ARCH=arm distclean
# 2. Use specific config
#    You can modify the config later by "make ARCH=arm menuconfig"
make ARCH=arm vexpress_defconfig
# 3. Build kernel
make -j 8 ARCH=arm
# 4. Build kernel modules
make -j 8 ARCH=arm modules
# 5: If you use uboot, need to run this step
#    Image: normal kernel, zImage: compressed kernel, uImage: used by uboot
#    Might need mkimage (Able to get from tools folder in u-boot)
make ARCH=arm uImage LOADADDR=0x60000000
# 6. Build device tree
make ARCH=arm dtbs

# If you only want to test file system and kernel, use the following commands to replace 3-6
make -j 8 ARCH=arm all
```

* Test with qemu
  - Should be panic since lack of file system

```bash
qemu-system-arm -M vexpress-a9 -m 512 -kernel arch/arm/boot/zImage -nographic -append "console=ttyAMA0" -dtb arch/arm/boot/dts/vexpress-v2p-ca9.dtb
```