# docker

# Useful Commands

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

