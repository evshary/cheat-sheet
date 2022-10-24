# Docker with GUI

Suggest to use [rocker](https://github.com/osrf/rocker), and it can help you run docker with GUI more easier.

# Issues

If you are using Intel Integrated GPU, `--devices /dev/dri` is necessary.

Refer to [here](https://github.com/osrf/rocker#intel-integrated-graphics-support)

If you want to force to run with NVIDIA GPU, you can use `sudo prime-select nvidia` and reboot to run with NVIDIA GPU.
