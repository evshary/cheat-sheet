# Yocto

[Yocto](https://www.yoctoproject.org/) can be used to build up your own Linux system.

# Usage

* Install necessary packages

```bash
sudo apt install gawk wget git diffstat unzip texinfo gcc build-essential chrpath socat cpio python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev pylint3 xterm python3-subunit mesa-common-dev zstd liblz4-tool
```

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

* Run qemu
  - Remember to source environment
  - Login with user root without password

```bash
runqemu qemuarm
# If you want run without graphic
runqemu qemuarm nographic
```

# bitbake

* List all recipes: `bitbake -s`
* Show the tasks in the recipes: `bitbake <recipe> -c listtasks`
  - `bitbake core-image-minimal -c listtasks`
* Run the specific recipe: `bitbake <recipe>`
  - `bitbake core-image-minimal`
* Show the environment of the recipe: `bitbake -e recipe`
  - `bitbake -e core-image-minimal`

# Reference

* [Official Documentation](https://docs.yoctoproject.org/current/index.html)
