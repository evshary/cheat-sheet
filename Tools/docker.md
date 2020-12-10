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
* docker run with the same SSH privilege as host
```
docker run -it --rm \
       -v $SSH_AUTH_SOCK:/ssh-agent \
       -e SSH_AUTH_SOCK=/ssh-agent \
       ubuntu:20.04 bash
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

# Support Normal User in docker
* Add the following line in Dockerfile to support normal user
```
ARG HOST_UID=1000
ARG HOST_GID=1000
ARG USER_NAME=user
RUN groupadd -g $HOST_GID $USER_NAME
RUN useradd --create-home --shell /bin/bash -u $HOST_UID -g $HOST_GID -G sudo $USER_NAME
RUN echo "ros ALL=(ALL) NOPASSWD:ALL" | sudo tee -a /etc/sudoers
USER $USER_NAME
```
