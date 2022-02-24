# Embedded Linux

To create your own system, you need to do the following works:

* [Create your compiler](compiler.md)
* [Create your own Linux system](kernel.md)
* [Create your rootfs](rootfs.md)
* [Create your uboot](uboot.md)

We use [qemu](qemu.md) here for simulation.

You can build the whole system with easier tools: [Buildroot](buildroot.md) and [Yocto](yocto.md).

# Reference
* Use the compiler from vendors, but lack of how to build uboot (gcc version is too old)
  - [https://hackmd.io/@c_0KKCwzQE2rsd39mpvNQQ/rknxhDzvB](https://hackmd.io/@c_0KKCwzQE2rsd39mpvNQQ/rknxhDzvB)
* Generate the compiler by yourself and build from the beginning to the end
  - [https://www.latelee.org/ellp/ellp-qemu-start.html](https://www.latelee.org/ellp/ellp-qemu-start.html)
* Use TFTP to boot from uboot to Linux
  - [https://www.itread01.com/content/1533316818.html](https://www.itread01.com/content/1533316818.html)
  - [https://www.itread01.com/content/1561550824.html](https://www.itread01.com/content/1561550824.html)
* [基於QEMU搭建完整的虛擬ARM開發環境(uboot+linux+rootfs)](https://www.itread01.com/content/1547681225.html)