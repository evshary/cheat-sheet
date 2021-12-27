# DKMS

DKMS is proposed by Dell for driver module management.
Driver needs to be recompiled while kernel upgrades, and DKMS wants to solve the problem.

* `sudo dkms add ./<module_src_folder>`: Add module source folder
* `sudo dkms build -m <module_name> -v <version>`: Build kernel module
* `sudo dkms install -m <module_name> -v <version>`: Install kernel module
* `sudo dkms status`: Show the list of kernel module
* `sudo dkms uninstall -m <module_name> -v <version>`: Uninstall kernel module
* `sudo dkms remove <module_name>/<version> --all`: Remove all the kernel module source
