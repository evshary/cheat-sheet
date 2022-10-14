# docker-compose

* Installation
  - Please refer to [official site](https://docs.docker.com/compose/install/).
```bash
sudo curl -L "https://github.com/docker/compose/releases/download/1.29.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
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
* Build container (not necessary)
```bash
docker-compose build
# Build without cache (rebuild)
docker-compose build --no-cache
```
* Run all the service
```bash
# Run without daemon
docker-compose up
# Run as daemon
docker-compose up -d
```
* Show running docker-compose
```bash
docker-compose ps
```
* Run specific service
  - Note that if you use run, then you can't stop all containers.
```bash
docker-compose run listener
```
* Run bash of specific service
```bash
docker-compose exec listener bash
```
* See the log
```bash
docker-compose logs listener
```
* Stop and clean
```bash
# stop service
docker-compose stop
# remove containers
docker-compose rm
# stop and remove containers
docker-compose down
```
