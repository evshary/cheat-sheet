# Yocto

[Yocto](https://www.yoctoproject.org/) can be used to build up your own Linux system.

# Usage

* Get the code
  - Choose stable LTS version: https://wiki.yoctoproject.org/wiki/Releases

```bash
git clone -b hardknott git://git.yoctoproject.org/poky.git
cd poky
```

* Setup environment (Will create conf folder)
  - `local.conf`: The device you use and the detail information of the building environment
    - You need to remove the comment of `#MACHINE ?= "qemuarm"`
  - `bblayers.conf`: The date layer you want to use
  - `templateconf.cfg`: Where to put other conf

```bash
# Will create build folder
source oe-init-build-env
```

* Create image

```bash
bitbake core-image-minimal
```

# Reference

* [Official Documentation](https://docs.yoctoproject.org/current/index.html)
