# LXD

# Usage

```bash
# launch container
lxc launch ubuntu:20.04 rosfoxy
lxc launch -p ros ubuntu:20.04 rosfoxy2
# list all images
lxc list
# execution
lxc exec container_name bash
lxc exec container_name -- su --login ubuntu
# stop
lxc stop Container_name
# delete
lxc delete container_name
```

# Reference

* [Basic Introduction to LXD](https://linuxhint.com/lxd-tutorial/)
* [How to install LXD on Ubuntu 20.04 (with some issues)](https://ubuntu.com/blog/installing-ros-in-lxd)

