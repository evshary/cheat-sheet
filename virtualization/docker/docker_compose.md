# docker-compose

* Installation: Follow [the official guide](https://docs.docker.com/compose/install/linux/)
  - I prefer to use [the repository installation](https://docs.docker.com/compose/install/linux/#install-using-the-repository)

```shell
# Install dependencies
sudo apt-get install ca-certificates curl gnupg
sudo install -m 0755 -d /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
sudo chmod a+r /etc/apt/keyrings/docker.gpg
echo \
  "deb [arch="$(dpkg --print-architecture)" signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  "$(. /etc/os-release && echo "$VERSION_CODENAME")" stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt-get update

# Install packages
sudo apt-get install docker-compose-plugin
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
docker compose build
# Build without cache (rebuild)
docker compose build --no-cache
```
* Run all the service
```bash
# Run without daemon
docker compose up
# Run as daemon
docker compose up -d
```
* Show running docker-compose
```bash
docker compose ps
```
* Run specific service
  - Note that if you use run, then you can't stop all containers.
```bash
docker compose run listener
```
* Run bash of specific service
```bash
docker compose exec listener bash
```
* See the log
```bash
docker compose logs listener
```
* Stop and clean
```bash
# stop service
docker compose stop
# remove containers
docker compose rm
# stop and remove containers
docker compose down
```
