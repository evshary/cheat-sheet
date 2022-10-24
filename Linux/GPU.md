# List GPU

* List GPU devices

```bash
lshw -c display
```

* Another way

```bash
# list GPU
lspci | grep VGA
# get detail
sudo lspci -vs [PCI bus number]
```

# Installation

## NVIDIA GPU in Ubuntu

* Install drivers

```bash
# Add NVIDIA repository
sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt update
# Install driver automatically
sudo ubuntu-drivers autoinstall
```

* Reboot and check how drivers work

```bash
nvidia-smi 
```

* Optional: If there are version conflicts, you can remove all nvidia packages and reinstall again.

```bash
# Remove all NVIDIA packages
sudo dpkg -P $(dpkg -l | grep nvidia | awk '{print $2}')
```

# Select GPU

* Chech which GPU you are using

```bash
prime-select query
```

* Decide to use NVIDIA GPU (Need to reboot)

```bash
prime-select nvidia
```

# stress GPU

Use [gpu-burn](https://github.com/wilicc/gpu-burn)

* Clone and build

```bash
git clone https://github.com/wilicc/gpu-burn.git
cd gpu-burn
make
```

* Run

```bash
./gpu-burn
```

# Benchmark GPU

Refer to [How can I tell, how well my graphics card performs on Ubuntu?](https://askubuntu.com/questions/1046812/how-can-i-tell-how-well-my-graphics-card-performs-on-ubuntu) and [
How to Benchmark your GPU on Linux](https://www.howtoforge.com/tutorial/linux-gpu-benchmark/)

Although there are 3 tools, we still suggest to use glmark2.
mesa-utils can't stress the GPU, and Valley can only run on x86 platform.
glmark2 will run several 3D model and show score in the end.

```bash
# installation
sudo apt install glmark2
# Run benchmark
glmark2 --fullscreen --show-all-options
```
