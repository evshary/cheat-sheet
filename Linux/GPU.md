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
