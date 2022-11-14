# Autoware

# Run prebuilt docker image

* Prerequisite

```shell
# Install necessary packages
sudo apt install python3-rocker
python3 -m pip install gdown
# Download map
mkdir ~/autoware_map
gdown -O ~/autoware_map/ 'https://docs.google.com/uc?export=download&id=1499_nsbUbIeturZaDj7jhUownh5fvXHd'
unzip -d ~/autoware_map ~/autoware_map/sample-map-planning.zip
```

## rocker without GPU

```shell
# Run rocker
rocker -e LIBGL_ALWAYS_SOFTWARE=1 --network host --privileged --x11 --user --volume $HOME/autoware_map -- ghcr.io/autowarefoundation/autoware-universe:latest-prebuilt-cuda bash
# Run example
ros2 launch autoware_launch planning_simulator.launch.xml map_path:=$HOME/autoware_map/sample-map-planning vehicle_model:=sample_vehicle sensor_model:=sample_sensor_kit
```

## rocker with GPU

* Intel integrated GPU

```shell
# Run rocker
rocker --devices /dev/dri --network host --privileged --x11 --user --volume $HOME/autoware_map -- ghcr.io/autowarefoundation/autoware-universe:latest-prebuilt-cuda bash
# Run example
ros2 launch autoware_launch planning_simulator.launch.xml map_path:=$HOME/autoware_map/sample-map-planning vehicle_model:=sample_vehicle sensor_model:=sample_sensor_kit
```

* NVIDIA GPU

```shell
# Run rocker
rocker --nvidia --network host --privileged --x11 --user --volume $HOME/autoware_map -- ghcr.io/autowarefoundation/autoware-universe:latest-prebuilt-cuda bash
# Run example
ros2 launch autoware_launch planning_simulator.launch.xml map_path:=$HOME/autoware_map/sample-map-planning vehicle_model:=sample_vehicle sensor_model:=sample_sensor_kit
```

## docker with GPU

```shell
# Allow permission
xhost +local:
# Run docker
docker run --gpus all --network host --privileged -it --rm -e QT_X11_NO_MITSHM=1 -e DISPLAY=$DISPLAY -e NVIDIA_DRIVER_CAPABILITIES=all -e __NV_PRIME_RENDER_OFFLOAD=1 -e __GLX_VENDOR_LIBRARY_NAME=nvidia -v /tmp/.X11-unix:/tmp/.X11-unix -v $HOME/autoware_map:/root/autoware_map ghcr.io/autowarefoundation/autoware-universe:latest-prebuilt-cuda bash
# Run example
ros2 launch autoware_launch planning_simulator.launch.xml map_path:=$HOME/autoware_map/sample-map-planning vehicle_model:=sample_vehicle sensor_model:=sample_sensor_kit
```
