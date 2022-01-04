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

# Installation

You need to use sdkmanager to install jetpack into nvidia platform.

* Install [sdkmanager](https://developer.nvidia.com/nvidia-sdk-manager)
* Follow the following steps: https://blog.csdn.net/caiguanhong/article/details/114550412

Note you need to sdkmanager can only run on ubuntu 18.04, so you need to fake your host PC to ubuntu 18.04.

* Backup `/usr/bin/os-release`
* Modify `/usr/bin/os-release` to the following
```bash
NAME="Ubuntu"
VERSION="18.04.5 LTS (Bionic Beaver)"
ID=ubuntu
ID_LIKE=debian
PRETTY_NAME="Ubuntu 18.04.5 LTS"
VERSION_ID="18.04"
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
VERSION_CODENAME=bionic
UBUNTU_CODENAME=bionic
```

# Build from source code

The latest jetpack can be downloaded from [the official website](https://developer.nvidia.com/embedded/jetpack)

The kernel in jetpack 4.6 is [L4T 32.6.1](https://developer.nvidia.com/embedded/linux-tegra-r3261).
  - You can download the driver packages & file system from the link above.

# tips

* Check jetpack version: `cat /etc/nv_tegra_release`
* Enable all the performance: `sudo nvpmodel -m 0`
* Show current jetpack status

```bash
pip install jetson-stats
# Or you can run this
python3 -m pip install jetson-stats
jtop
```
* Check jetson version: `jetson_release`
* [How to upgrade nvidia jetson to Ubuntu 20.04](https://viking-drone.com/wiki/upgrading-nvidia-jetson-xavier-nx-to-ubuntu-20-04/)

# docker

* docker image from nvidia: https://catalog.ngc.nvidia.com/containers
* Dockerfile: https://gitlab.com/nvidia/container-images/l4t-base
* jetson container for ROS: https://github.com/dusty-nv/jetson-containers
* Run docker with Ubuntu 20.04 in jetson series: https://forums.developer.nvidia.com/t/cuda-enabled-ubuntu-20-04-docker-images-for-jetson/186418

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

## Note
* Unable to run docker with the recent nvidia-container-runtime
  - Refer to [Docker fails to create container after upgrading docker on Jetpack 4.9](https://github.com/dusty-nv/jetson-containers/issues/108)

# AI

Refer to [NVIDIA Jetson Nano — 02 執行深度學習範例：影像辨識、物件偵測、影像分割、人體姿勢預測](https://d246810g2000.medium.com/nvidia-jetson-nano-for-jetpack-4-4-02-%E5%9F%B7%E8%A1%8C%E6%B7%B1%E5%BA%A6%E5%AD%B8%E7%BF%92%E7%AF%84%E4%BE%8B-%E5%BD%B1%E5%83%8F%E8%BE%A8%E8%AD%98-%E7%89%A9%E4%BB%B6%E5%81%B5%E6%B8%AC-%E5%BD%B1%E5%83%8F%E5%88%86%E5%89%B2-%E4%BA%BA%E9%AB%94%E5%A7%BF%E5%8B%A2%E9%A0%90%E6%B8%AC-2e39f1734a8e) or [深入使用NVIDIA Jetson Inference機器學習專案 - 電腦視覺圖片分類任務](https://www.rs-online.com/designspark/nvidia-jetson-inference-cn) for how to run AI inference on jetson.

* The packages for AI: [jetson-release](https://github.com/dusty-nv/jetson-inference)
* ROS packages for AI on jetson: [ros_deep_learning](https://github.com/dusty-nv/ros_deep_learning)
