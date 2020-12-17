# docker
## Useful Commands
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
* Copy file into / outside container
```
# outside
docker cp <container ID>:<src> <dst>
# into
docker cp <src> <container ID>:<dst>
```

## Save & Export
* Save & Load: Save the current image status
```
docker save [image_name]:[tag] > [name].tar
docker load < [name].tar
```
* Export & Import: Export the current container status (including filesystem changes)
```
docker export [container_name] > [name].tar
cat [name].tar | docker import - [image_name]:[tag]
```

## Tips
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

# docker registry
* Run registry server
```
mkdir registry
docker run --rm -d -p 5000:5000 -v $PWD/registry:/var/lib/registry --name registry registry:2
```
* Optional: Run web server to see the current images
```
docker run --rm -it -p 8080:8080 -d --name registry-web --link registry -e REGISTRY_URL=http://registry:5000/v2 -e REGISTRY_NAME=localhost:5000 hyper/docker-registry-web
```
* Tag and push
```
docker tag [image_name]:[tag] 127.0.0.1:5000/[image_name]
docker push 127.0.0.1:5000/[image_name]
```
* Pull from docker Hub
```
docker pull 127.0.0.1:5000/[image_name]
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

# Dockerfile
## Build docker image from Dockerfile
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

## Support Normal User in docker
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

# docker management
## docker-mahcine
* Install docker machine
  - Refer to https://docs.docker.com/machine/install-machine/
```
base=https://github.com/docker/machine/releases/download/v0.16.0 &&
  curl -L $base/docker-machine-$(uname -s)-$(uname -m) >/tmp/docker-machine &&
  sudo mv /tmp/docker-machine /usr/local/bin/docker-machine &&
  chmod +x /usr/local/bin/docker-machine
```
* Create machine
```
docker-machine create --driver virtualbox [vm_name]
```
* List machine / get IP / get env
```
docker-machine ls
docker-machine ip [vm_name]
docker-machine env [vm_name]
# If you can't run env, please regenerate certificate
docker-machine regenerate-certs [vm_name]
```
* Run/Stop machine
```
docker-machine start [vm_name]
docker-machine stop [vm_name]
```
* Control machine
```
docker-machine ssh [vm_name]
```
## docker swarm
There is two parts in docker swarm: swarm manager & worker node

swarm manager can put docker service into worker node.

The diagram is from [docker documentation](https://docs.docker.com/engine/swarm/how-swarm-mode-works/services/).

![](https://docs.docker.com/engine/swarm/images/services-diagram.png)

### swarm
* Select machine to become manager
```
# Connect to machine
docker-machine ssh [vm_name]
# Change into swarm manager
docker swarm init --advertise-addr [machine IP]
```
* Copy the output like the following and run in other machine
```
docker swarm join --token [token] [machine IP]:2377
```
* Leave the swarm
```
docker swarm leave
```
### node
* Now you can manage other machines from manager
```
# show the swarm info
docker node ls
# Promote node to manager
docker node promote [vm_name]
# Demote manager to node
docker node demote [vm_name]
```
* Start / Stop node
```
# stop node
docker node update --availability drain [vm_name]
# start node
docker node update --availability active [vm_name]
```
### service
* Run service on node
  - `--replicas n` means run in n machines
```
docker service create --replicas n --name [service_name] [images] [command]
# EX: docker service create --replicas 1 --name ros_talker osrf/ros:foxy-desktop ros2 run demo_nodes_py talker
```
* Show service info
```
docker service ls
docker service ps [service_name]
docker service inspect --pretty [service_name]
```
* Stop service
```
docker service rm [service_name]
```
### stack
Refer to https://docs.docker.com/engine/swarm/stack-deploy/

* Create docker-compose file in your swarm manager
* Deploy compose-file
```
docker stack deploy -c docker-compose.yml [APP name]
```
* Stop service from compose-file
```
docker stack rm [APP name]
```
