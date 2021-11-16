# JetPack

JetPack: JetsonDevelopment Pack

![image](https://user-images.githubusercontent.com/456210/141880836-5af1ae87-045f-4fbf-8431-ed2333b54620.png)
[image source](https://docs.nvidia.com/jetson/l4t/index.html#page/Tegra%20Linux%20Driver%20Package%20Development%20Guide/overview.html)

* Components:
  - Deep learning: TensorRT(Inference), cuDNN(Training)
  - Computer Vision: NVIDIA VisionWorks(Vision API with CUDA supported), OpenCV, VPI(Replace VisionWorks)
  - GPU: CUDA
  - Graphics: OpenGL, EGL...
  - Multimedia: V4L2 library, Gstreamer, CODEC

Deepstream SDK: Build seamless streaming pipelines for AI-based video, audio, and image analytics.

![image](https://user-images.githubusercontent.com/456210/141881460-500a4754-37d2-4377-9392-c76f68bbd0d4.png)
[image source](https://galliot.us/2020/06/01/deepstream-sdk/)

# tips

* Enable all the performance: `sudo nvpmodel -m 0`
* Show current jetpack status

```bash
pip install jetson-stats
jtop
```
* Check jetson version: `jetson_release`
* [How to upgrade nvidia jetson to Ubuntu 20.04](https://viking-drone.com/wiki/upgrading-nvidia-jetson-xavier-nx-to-ubuntu-20-04/)

# docker

* docker image from nvidia: https://catalog.ngc.nvidia.com/containers
* Dockerfile: https://gitlab.com/nvidia/container-images/l4t-base
* jetson container for ROS: https://github.com/dusty-nv/jetson-containers

## Example

Refer to [【邊緣AI系列】在NVIDIA Jetson NANO 上使用 Docker Container 部署視覺應用](https://grady1006.medium.com/%E9%82%8A%E7%B7%A3ai%E7%B3%BB%E5%88%97-%E5%9C%A8nvidia-jetson-nano-%E4%B8%8A%E4%BD%BF%E7%94%A8-docker-container-%E9%83%A8%E7%BD%B2%E8%A6%96%E8%A6%BA%E6%87%89%E7%94%A8-1719b2062f15)

* Run docker
```bash
docker pull nvcr.io/nvidia/l4t-base:r32.4.3
xhost +
docker run -it --rm --net=host --runtime nvidia  -e DISPLAY=$DISPLAY -v /tmp/.X11-unix/:/tmp/.X11-unix nvcr.io/nvidia/l4t-base:r32.4.3
```
* Run example
```bash
apt-get update && apt-get install -y --no-install-recommends make g++
cp -r /usr/local/cuda/samples /tmp
cd /tmp/samples/5_Simulations/nbody
make
./nbody
```
