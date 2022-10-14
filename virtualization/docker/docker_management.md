# docker management

This page will show how to 

# docker-mahcine
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
* Remove unused machines
```bash
docker-machine rm [vm_name]
# force to remove
docker-machine rm -f [vm_name]
```

# docker swarm

There is two parts in docker swarm: swarm manager & worker node

swarm manager can put docker service into worker node.

The diagram is from [docker documentation](https://docs.docker.com/engine/swarm/how-swarm-mode-works/services/).

![](https://docs.docker.com/engine/swarm/images/services-diagram.png)

## swarm

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

## node

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

## service

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

## stack

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
