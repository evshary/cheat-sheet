# Dockerfile

This page guides you how to write your own Dockerfile.

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
```bash
docker build -t myimage:mytag .
# If you want to assign Dockerfile name
docker build -t myimage:mytag -f myDockerfile .
```
* Run
```bash
docker run -it --rm myimage:mytag
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

# Other tips

* Avoid interactive while installing tzdata
  - tzdata requires entering your timezone while installing, which will cause problems to `docker build`
```bash
# Add environmental variables
ENV DEBIAN_FRONTEND="noninteractive"
ENV TZ="Asia/Taipei"
# or run like the following
RUN DEBIAN_FRONTEND="noninteractive" TZ="Asia/Taipei" apt-get -qqy install tzdata
```
* Enable modify Network Manager in host
  - Refer to https://stackoverflow.com/questions/52654962/nmcli-in-a-docker-container/54914701
```bash
docker run --privileged --network=host --volume /var/run/dbus:/var/run/dbus [Your Args]
```

