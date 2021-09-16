# docker
## Useful Commands
* Run Ubuntu 20.04 for testing
```bash
sudo docker run --rm -it ubuntu:20.04 bash
```
* Run ROS 2 foxy for testing
```bash
sudo docker run --rm -it ros:foxy bash
```
* Show docker log
```bash
sudo docker logs <container ID>
```
* Prune
```bash
# Remove all dangling images
sudo docker image prune
# Remove stopped containers
sudo docker container prune
```
* Copy file into / outside container
```bash
# outside
docker cp <container ID>:<src> <dst>
# into
docker cp <src> <container ID>:<dst>
```

## volume
* List current volume
```bash
docker volume ls
```
* Create the volume
  - Default will put under `/var/lib/docker/volumes`
```bash
docker volume create myvolume
```
* Inspect the volume
```bash
docker volume inspect myvolume
```
* Run docker with volume
  - Mount the myvolume on /myspace in docker
```bash
docker run --rm -it -v myvolume:/myspace ubuntu:bionic bash
```
* Remove volume
```bash
# Remove certain volume
docker volume rm myvolume
# NOTE: This will remove all the unused volume!
docker volume prune
```

## Save & Export
* Save & Load: Save the current image status
```bash
docker save [image_name]:[tag] > [name].tar
docker load < [name].tar
```
* Export & Import: Export the current container status (including filesystem changes)
```bash
docker export [container_name] > [name].tar
cat [name].tar | docker import - [image_name]:[tag]
```

## Tips
* Able to use docker without sudo
```bash
sudo groupadd docker
sudo gpasswd -a $USER docker
# logout and login
```
* docker run with the same SSH privilege as host
```bash
docker run -it --rm \
       -v $SSH_AUTH_SOCK:/ssh-agent \
       -e SSH_AUTH_SOCK=/ssh-agent \
       ubuntu:20.04 bash
```
* Use the same time with the host
```bash
docker run -it --rm \
       -v /etc/localtime:/etc/localtime:ro \
       ubuntu:2004 bash
```

# docker registry
* Run registry server
```bash
mkdir registry
docker run --rm -d -p 5000:5000 -v $PWD/registry:/var/lib/registry --name registry registry:2
```
* Optional: Run web server to see the current images
```bash
docker run --rm -it -p 8080:8080 -d --name registry-web --link registry -e REGISTRY_URL=http://registry:5000/v2 -e REGISTRY_NAME=localhost:5000 hyper/docker-registry-web
```
* Tag and push
```bash
docker tag [image_name]:[tag] 127.0.0.1:5000/[image_name]
docker push 127.0.0.1:5000/[image_name]
```
* Pull from docker Hub
```bash
docker pull 127.0.0.1:5000/[image_name]
```

# docker-compose
* Installation
  - Please refer to [official site](https://docs.docker.com/compose/install/).
```bash
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
* Run all the service
```bash
docker-compose up -d
```
* Run specific service
```bash
docker-compose run listener
```
* See the log
```bash
docker-compose logs listener
```
* Stop and clean
```bash
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
```bash
docker build -t myimage:mytag .
```
* Run
```bash
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

## Other tips
* Avoid interactive while installing tzdata
  - tzdata requires entering your timezone while installing, which will cause problems to `docker build`
```bash
RUN DEBIAN_FRONTEND="noninteractive" TZ="Asia/Taipei" apt-get -qqy install tzdata
```
* Enable modify Network Manager in host
  - Refer to https://stackoverflow.com/questions/52654962/nmcli-in-a-docker-container/54914701
```bash
docker run --privileged --network=host --volume /var/run/dbus:/var/run/dbus [Your Args]
```

# docker management
## docker-mahcine
* Install docker machine
  - Refer to https://docs.docker.com/machine/install-machine/
```bash
base=https://github.com/docker/machine/releases/download/v0.16.0 &&
  curl -L $base/docker-machine-$(uname -s)-$(uname -m) >/tmp/docker-machine &&
  sudo mv /tmp/docker-machine /usr/local/bin/docker-machine &&
  chmod +x /usr/local/bin/docker-machine
```
* Create machine
```bash
docker-machine create --driver virtualbox [vm_name]
```
* List machine / get IP / get env
```bash
docker-machine ls
docker-machine ip [vm_name]
docker-machine env [vm_name]
# If you can't run env, please regenerate certificate
docker-machine regenerate-certs [vm_name]
```
* Run/Stop machine
```bash
docker-machine start [vm_name]
docker-machine stop [vm_name]
```
* Control machine
```bash
docker-machine ssh [vm_name]
```
## docker swarm
There is two parts in docker swarm: swarm manager & worker node

swarm manager can put docker service into worker node.

The diagram is from [docker documentation](https://docs.docker.com/engine/swarm/how-swarm-mode-works/services/).

![](https://docs.docker.com/engine/swarm/images/services-diagram.png)

### swarm
* Select machine to become manager
```bash
# Connect to machine
docker-machine ssh [vm_name]
# Change into swarm manager
docker swarm init --advertise-addr [machine IP]
```
* Copy the output like the following and run in other machine
```bash
docker swarm join --token [token] [machine IP]:2377
```
* Leave the swarm
```bash
docker swarm leave
```
### node
* Now you can manage other machines from manager
```bash
# show the swarm info
docker node ls
# Promote node to manager
docker node promote [vm_name]
# Demote manager to node
docker node demote [vm_name]
```
* Start / Stop node
```bash
# stop node
docker node update --availability drain [vm_name]
# start node
docker node update --availability active [vm_name]
```
### service
* Run service on node
  - `--replicas n` means run in n machines
```bash
docker service create --replicas n --name [service_name] [images] [command]
# EX: docker service create --replicas 1 --name ros_talker osrf/ros:foxy-desktop ros2 run demo_nodes_py talker
```
* Show service info
```bash
docker service ls
docker service ps [service_name]
docker service inspect --pretty [service_name]
```
* Stop service
```bash
docker service rm [service_name]
```
### stack
Refer to https://docs.docker.com/engine/swarm/stack-deploy/

* Create docker-compose file in your swarm manager
* Deploy compose-file
```bash
docker stack deploy -c docker-compose.yml [APP name]
```
* Stop service from compose-file
```bash
docker stack rm [APP name]
```
