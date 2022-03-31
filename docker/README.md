# docker

# Useful Commands

* Run Ubuntu 20.04 for testing
```bash
docker run --rm -it ubuntu:20.04 bash
```

* Run ROS 2 foxy for testing
```bash
docker run --rm -it ros:foxy bash
```

* Show docker log
```bash
docker logs <container ID>
```

* Disk usage & Prune
```bash
# Show disk usage
docker system df
# Remove all dangling images
docker image prune
# Remove stopped containers
docker container prune
# Clean all the things
docker system prune
# Also clean unused images and volumes
docker system prune -a --volumes
```

* Copy file into / outside container
```bash
# outside
docker cp <container ID>:<src> <dst>
# into
docker cp <src> <container ID>:<dst>
```

* Show docker container size
```bash
docker ps -a --size
```

* Analyze docker's layer size
```bash
docker history <image>
```

* Show status of container (CPU, memory status...)

```bash
docker stats
```

# volume

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

# Save & Export

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

# Useful shell scripts

* Check image exist or not
```bash
if [ ! "$(docker images -q $image_name)" ]; then
fi
```

* Check container exist or not
```bash
if [ ! "$(docker ps -aq -f name=$container_name)" ]; then
fi
```

* Check container status
```bash
# Exited
if [ "$(docker ps -aq -f status=exited -f name=$container_name)" ]; then
fi
# Running
if [ "$(docker ps -aq -f status=running -f name=$container_name)" ]; then
fi
```

# reverse docker

* How to build docker image: `docker history --no-trunc <docker-image>`
* How to run docker container: `docker inspect <container_name>`

# Tips

* Able to use docker without sudo
```bash
sudo groupadd docker
sudo gpasswd -a $USER docker
# run `newgrp docker` or logout&login 
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

* Whether running in container
```bash
if [ -f /.dockerenv ]; then
    echo "In the container"
else
    echo "Not in the container"
fi
```

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

* Remove multiple images with wildcard filter

```bash
docker rmi -f $(docker images --filter=reference="*myimage*" -q)
```

* Remove all exited containers

```bash
docker rm -f $(docker ps -a --filter=status="exited" -q)
```
