# Yocto

[Yocto](https://www.yoctoproject.org/) can be used to build up your own Linux system.

# Concept

* bitbake: The task executor and scheduler for Yocto
* build > meta-layers > recipes > tasks
  - The build system(`build/conf/bblayers.conf`) will include several meta-layers
  - The meta-layer(`meta-name/conf/layer.conf`) contain several recipes
  - The recipe(end with `.bb`) defines the tasks, including do_install, do_compile...

# Usage

The following figure from Yocto official website shows how we generates build environment in Yocto.

![image](https://user-images.githubusercontent.com/456210/155638914-b618de42-daa0-4683-8fae-9c93b97a0292.png)

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

# metalayer

Yocto uses metalayer to build system.

The figure shows how the layers consist of build system.

![image](https://user-images.githubusercontent.com/456210/155637711-9c695f8c-4862-489b-a6c8-9db4b4eb7242.png)
[img src](https://www.aosabook.org/en/yocto.html)

The figure from official website shows the file architecture of metalayer.

![image](https://user-images.githubusercontent.com/456210/155639257-d1d2527a-9320-47d5-83d5-8d8e1a0a25e6.png)

* Create new layers "custom"

```bash
source oe-init-build-env
# custom folder will be created under build
bitbake-layers create-layer custom
```

* Modify `conf/bblayers.conf` and add the path in BBLAYERS

```bash
BBLAYERS ?= " \
  /home/chenying/embedded_linux/poky/meta \
  /home/chenying/embedded_linux/poky/meta-poky \
  /home/chenying/embedded_linux/poky/meta-yocto-bsp \
  /home/chenying/embedded_linux/poky/build/custom \
  "
```

* In fact, you can add / remove metalayer with commands

```bash
bitbake-layers add-layer custom
bitbake-layers remove-layer custom
```

* Show the current metalyare / recipes

```bash
bitbake-layers show-layers
bitbake-layers show-recipes
```

* You can modify the metalayer properties in `custom/conf/layer.conf`

# Reference

* [Official Documentation](https://docs.yoctoproject.org/current/index.html)
* [Yocto Project Overview and Concepts Manual](https://www.yoctoproject.org/docs/2.5/overview-manual/overview-manual.html)
