# Linux driver

## Example

* dummy_example: show an example driver which can also create /dev/dummy device node.
* parameter_example: an example driver which can receive parameters from users.

## Useful tools

* `lsmod`: List the modules loaded now
* `sudo insmod xxx.ko`: Insert module
* `sudo rmmod xxx.ko`: Remove module
* modprobe: same as insmod & rmmod, but also deal with module dependencies
```bash
# insert module
sudo modprobe xxx
# remove module
sudo modprobe -r xxx
```
* depmod:
`sudo depmod`

## The mapping between user and kernel driver operation

| user | kernel |
| - | - |
| open | open |
| close | release 
| read/pread | read |
| write/pwrite | write |
| ioctl | ioctl/unlocked_ioctl |
| llseek | llseek/lseek |
| select | poll |
| mmap | mmap |

## reference

* [ch8: 裝置驅動程式的基本知識](https://hackmd.io/@splasky/SJ4so_DXe?type=view): Some examples of Linux driver.
* 你也可以撰寫Linux核心：從嵌入式系統切入 / 嵌入式Linux驱动模板精讲与项目实践 (林錫龍)

# DKMS

DKMS is proposed by Dell for driver module management.
Driver needs to be recompiled while kernel upgrades, and DKMS wants to solve the problem.

* `sudo dkms add ./<module_src_folder>`: Add module source folder
* `sudo dkms build -m <module_name> -v <version>`: Build kernel module
* `sudo dkms install -m <module_name> -v <version>`: Install kernel module
* `sudo dkms status`: Show the list of kernel module
* `sudo dkms uninstall -m <module_name> -v <version>`: Uninstall kernel module
* `sudo dkms remove <module_name>/<version> --all`: Remove all the kernel module source
