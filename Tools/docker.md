# Useful Commands
* Run Ubuntu 20.04 for testing
```
sudo docker run --rm -it ubuntu:20.04 bash
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
