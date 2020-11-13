# Useful Commands
* Run Ubuntu 20.04 for testing
```
sudo docker run --rm -it ubuntu:20.04 bash
```
* Run ROS 2 foxy for testing
```
sudo docker run --rm -it ros:foxy bash
```
* Show docker log
```
sudo docker logs <container ID>
```
* Prune
```
# Remove all dangling images
sudo docker image prune
# Remove stopped containers
sudo docker container prune
```

# Build docker image from Dockerfile
* Create Dockerfile
```
FROM ros:foxy

# install ros package
RUN apt-get update && apt-get install -y \
      ros-${ROS_DISTRO}-demo-nodes-cpp \
      ros-${ROS_DISTRO}-demo-nodes-py && \
    rm -rf /var/lib/apt/lists/*

# launch ros package
CMD ["ros2", "launch", "demo_nodes_cpp", "talker_listener.launch.py"]
```
* Build docker image
```
docker build -t myimage:mytag .
```
* Run
```
docker run -it --rm myimage:mytag
```

# Useful Operations
* Able to use docker without sudo
```
sudo groupadd docker
sudo gpasswd -a $USER docker
# logout and login
```

# docker-compose
* Installation
  - Please refer to [official site](https://docs.docker.com/compose/install/).
```
sudo curl -L "https://github.com/docker/compose/releases/download/1.27.4/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
```
* Create docker-compose.yml
```yml
version: '3'
services:
  talker:
     image: osrf/ros:foxy-desktop
     command: ros2 run demo_nodes_py talker
  listener:
     image: osrf/ros:foxy-desktop
     command: ros2 run demo_nodes_py listener
```
* Run
```
docker-compose up -d
```
* See the log
```
docker-compose logs listener
```
* Stop and clean
```
docker-compose stop
docker-compose rm
```
