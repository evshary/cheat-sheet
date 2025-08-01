# GPU

## List GPU

* List GPU devices

```shell
lshw -c display
```

* Another way

```shell
# list GPU
lspci | grep VGA
# get detail
sudo lspci -vs [PCI bus number]
```

## Installation

### NVIDIA GPU in Ubuntu

* Install drivers

```shell
# Add NVIDIA repository
sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt update
# Install driver automatically
sudo ubuntu-drivers autoinstall
```

* Reboot and check how drivers work

```shell
# Show NVIDIA GPU status
nvidia-smi
# Show NVIDIA GPU settings
sudo nvidia-settings
```

* Optional: If there are version conflicts, you can remove all nvidia packages and reinstall again.

```shell
# Remove all NVIDIA packages
sudo dpkg -P $(dpkg -l | grep nvidia | awk '{print $2}')
```

### CUDA

* Install

```shell
sudo apt install cuda
```

* Remember to add the environmental variables in the `~/.profile`

```shell
export PATH=/usr/local/cuda/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH
```

* Check the version

```shell
# CUDA Toolkit version
nvcc --version
# The highest version GPU driver supports
nvidia-smi
```

* Uninstall

```shell
sudo apt remove "cuda-*"
# If there is dependency issue, run the following command first
sudo apt remove "libnv*"
```

## Select GPU

* Chech which GPU you are using

```shell
prime-select query
```

* Decide to use NVIDIA GPU (Need to reboot)
  * If the command doesn't work, make sure gpu-manager is working: `sudo systemctl enable gpu-manager`

```shell
prime-select nvidia
```

* Test which GPU is running

```shell
sudo apt install mesa-utils
glxinfo | grep vendor
```

* Optional: you can use environmental variables to make some application run on NVIDIA GPU
  * Refer to [Prime-select - Nvidia selected but not used](https://forums.developer.nvidia.com/t/prime-select-nvidia-selected-but-not-used/121108/4)

```shell
__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia glxinfo | grep vendor
```

* Note: I found that the system will use your display GPU as default, so use the display of the GPU you want to set as default is a better idea.

## stress GPU

Use [gpu-burn](https://github.com/wilicc/gpu-burn)

* Clone and build

```shell
git clone https://github.com/wilicc/gpu-burn.git
cd gpu-burn
make
```

* Run

```shell
./gpu_burn
```

## Benchmark GPU

Refer to [How can I tell, how well my graphics card performs on Ubuntu?](https://askubuntu.com/questions/1046812/how-can-i-tell-how-well-my-graphics-card-performs-on-ubuntu) and [How to Benchmark your GPU on Linux](https://www.howtoforge.com/tutorial/linux-gpu-benchmark/)

Although there are 3 tools, we still suggest to use glmark2.
mesa-utils can't stress the GPU, and Valley can only run on x86 platform.
glmark2 will run several 3D model and show score in the end.

```shell
# installation
sudo apt install glmark2
# Run benchmark
glmark2 --fullscreen --show-all-options
```
