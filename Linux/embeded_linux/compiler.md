# Compile Tool

There are 3 ways to create compiler:

1. crosstool-NG
2. Download from vendors
3. Download from Linux distribution

# crosstool-NG

Use crosstool-NG to build your own compiler tool

* Download crosstool-NG from [`http://crosstool-ng.org/download/crosstool-ng/`](http://crosstool-ng.org/download/crosstool-ng/)
* Decompress and build
    
```bash
tar xf crosstool-ng-1.24.0-rc3.tar.bz2
cd crosstool-ng-1.24.0-rc3
./configure --enable-local
make
```
    
* Select your cross compiler
    
```bash
# List all the settings
./ct-ng list-samples
# show settings
./ct-ng show-arm-unknown-linux-gnueabi
# select your settings
./ct-ng arm-unknown-linux-gnueabi
# Configure
# Remove "Render the toolchain read-only" from "Paths and misc options"
# Select "hardware (FPU)" in "Target options => Floating point"
# Add "--enable-obsolete-rpc" in "C-library => extra config"
./ct-ng menuconfig
# Fix issues: https://github.com/crosstool-ng/crosstool-ng/issues/1625
sed -e 's|CT_ISL_MIRRORS=.*$|CT_ISL_MIRRORS="https://libisl.sourceforge.io"|' \
    -e 's|CT_EXPAT_MIRRORS=.*$|CT_EXPAT_MIRRORS="https://github.com/libexpat/libexpat/releases/download/R_2_2_6"|' \
    -i .config
# Compile
./ct-ng build
```
    
* Compiler will be under `~/x-tools/arm-unknown-linux-gnueabihf/bin/` and we need to add PATH

```bash
export PATH=~/x-tools/arm-unknown-linux-gnueabihf/bin/:$PATH
```

# Download existed compiler from vendors

Here are several sources you can download toolchain:

* ARM official website: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
* Linaro: https://www.linaro.org/downloads/
* mentor.com(Acquired by Siemens): http://cursuri.cheche.ro/sourcery.mentor.com/public/gnu_toolchain/arm-none-linux-gnueabi/

```bash
wget https://sourcery.mentor.com/GNUToolchain/package12813/public/arm-none-linux-gnueabi/arm-2014.05-29-arm-none-linux-gnueabi-i686-pc-linux-gnu.tar.bz2
tar xvf arm-2014.05-29-arm-none-linux-gnueabi-i686-pc-linux-gnu.tar.bz2
export PATH=<path to "arm-2014.05/bin">:$PATH
# for example
export PATH=~/workspace/cross_compiler_test/arm-2014.05/bin/:$PATH
```

# Download from Linux distribution

## Gentoo

* `-t target`: target format: `CPU-HW-OS-Clib`
  - `CPU architecture`：alpha, arm, i386, x86_64...
  - `Hardware Platform / Vendor`：pc, unknown...
  - `Operating System`：linux, elf, uclinux...
  - `C Library`：eabi, gnu, gnueabi, uclibc
  - EX: i686-pc-linux-gnu, x86_64-pc-linux-gnu, armv7a-hardfloat-linux-gnueabi, arm-unknown-linux-gnu
* `-S`：Use stable
* `-v`：verbose

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
sudo apt-get install gcc-arm-linux-gnueabi
# Build
arm-linux-gnueabi-gcc --static test.c -o test
# Execution
qemu-arm test
# You need to link library, you don't build with static link (-L means library path)
qemu-arm -L /usr/arm-linux-gnueabi/ test
```
