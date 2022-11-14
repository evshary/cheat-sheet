# Docker with GUI

There are 2 ways to run GUI with container: docker & rocker.
Suggest to use [rocker](https://github.com/osrf/rocker), and it can help you run docker with GUI more easier.

* Run GUI application in docker container

```bash
# Allow permission
xhost +local:
# Pass .X11-unix
docker run -it --rm -v /tmp/.X11-unix:/tmp/.X11-unix --env="QT_X11_NO_MITSHM=1" --env "DISPLAY=$DISPLAY" ros:foxy
# Test GUI in docker
#apt update && apt install -y ros-foxy-rviz2
#source /opt/ros/foxy/setup.bash
#rviz2
```

* Using rocker

```bash
sudo apt install python3-rocker
# If you use Intel GPU
rocker --x11 --user --devices /dev/dri --home ros:foxy bash
# If you use NVIDIA GPU
rocker --nvidia --x11 --user --home ros:foxy bash
# Test GUI in docker
#apt update && apt install -y ros-foxy-rviz2
#source /opt/ros/foxy/setup.bash
#rviz2
```

# Run with GPU

* docker

```bash
# Allow permission
xhost +local:
# Run with Autoware
docker run --gpus all --network host --privileged -it --rm -e QT_X11_NO_MITSHM=1 -e DISPLAY=$DISPLAY -e NVIDIA_DRIVER_CAPABILITIES=all -e __NV_PRIME_RENDER_OFFLOAD=1 -e __GLX_VENDOR_LIBRARY_NAME=nvidia -v /tmp/.X11-unix:/tmp/.X11-unix -v $HOME/autoware_map:/root/autoware_map ghcr.io/autowarefoundation/autoware-universe:latest-prebuilt-cuda bash
ros2 launch autoware_launch planning_simulator.launch.xml map_path:=$HOME/autoware_map/sample-map-planning vehicle_model:=sample_vehicle sensor_model:=sample_sensor_kit
```

* rocker

```bash
rocker --nvidia --network host --privileged --x11 --user --volume $HOME/autoware_map -- ghcr.io/autowarefoundation/autoware-universe:latest-prebuilt-cuda bash
ros2 launch autoware_launch planning_simulator.launch.xml map_path:=$HOME/autoware_map/sample-map-planning vehicle_model:=sample_vehicle sensor_model:=sample_sensor_kit
```

# Issues

If you are using Intel Integrated GPU, `--devices /dev/dri` is necessary.

Refer to [here](https://github.com/osrf/rocker#intel-integrated-graphics-support)

If you want to force to run with NVIDIA GPU, you can use `sudo prime-select nvidia` and reboot to run with NVIDIA GPU.
