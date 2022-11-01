# Introduction

Kubernetes is a system which can help us deploy / manage containerized application.

* Deploy multiple container to multipe machines
* Manage the status of containers
* Transfer containers between machines
* Scalability: from one machine to multiple machines

# Architecture

* Kubernetes Cluster = 1 Master + N Node
* Mater (Control Plane): Control node
  * API Server
    * entry for REST & kubectl
    * Able to control all components
  * etcd
    * Save k8s cluster data
  * Scheduler
    * Schedule pod to node
  * Controller Manager
  * Cloud Controller Manager
* Node
  * kubelet: Manage all Pods on the node and communicate with master
  * kube-proxy: Send the Pods info on the node to iptables. Make Pods can be accessed by others in the cluster
  * container runtime

## Pod

In k8s, Pod equals to an application, including YAML file and several container.

# Tools

## minikube

[Official Website](https://minikube.sigs.k8s.io/docs/start/)

Able to create k8s cluster

```bash
# Enable k8s cluster
minikube start
# Check status
minikube status
```

## kubectl

* [installation](https://kubernetes.io/docs/tasks/tools/install-kubectl-linux/)
* [cheat-sheet](https://kubernetes.io/docs/reference/kubectl/cheatsheet/)

Used to control k8s cluster

### Basic operation

* View global config

```bash
kubectl config view
```

* Create from YAML

```bash
kubectl create -f xxx.yaml
```

* View, find resources

```bash
# pod
kubectl get pods -o wide # List all pods with detail in current namspace
kubectl get pods -A      # List all pods in all namepsaces
kubectl get pods <pod_name> -o yaml # Get pod's YAML
# nodes
kubectl get nodes -o wide # List node with detail
# information
kubectl describe nodes <node_name>
kubectl describe pods <pod_name>
```

* Run & delete

```bash
# Run
kubectl run <pod_name> --image=<image_path> --port=<expose_port>
## EX: kubectl run hello-minikube --image=gcr.io/google_containers/echoserver:1.8 --port=8080

# Delete
kubectl delete pods <pod_name>
## EX: kubectl delete pods hello-minikube
```

### create & apply YAML

```bash
# apply
kubectl apply -f pod.yaml
# create
kubectl create -f pod.yaml
# delete deploy
kubectl delete -f pod.yaml
```

The difference between create and apply:

* kubectl create:
  * Command management: Tell k8s API what to create, replace, delete
  * Need to delete the resource and recreate, so need complete YAML file
  * Can not create repeatedly
* kubectl apply:
  * Declarative management: Able to modify based on current status
  * YAML does not need to be complete and can only contain fields which need to be updated
  * Can create repeatedly

### Interact with pod

1. kubectl port-forward

```bash
# forward port outside
kubectl port-forward <pod_name> <host_port>:<pod_port>
```

2. Create a service

```bash
# Creat service
kubectl expose pod <pod_name> --type=NodePort --name=<service_name>
# Show all service
kubectl get services
# Show the url mapped by minikube
minikube service <service_name> --url
```

### Debug

* Enter into running pods

```bash
# Run command
kubectl exec <pod_name> -- <command>
# Enter shell
kubectl exec --stdin --tty <pod_name> -- /bin/bash
```

* Use alpine to check cluster

```bash
# Run minimun image alpine
kubectl run -i --tty alpine --image alpine --restart=Never -- sh
# Install necessary packages
apk add --no-cache curl
# Curl the IP:port
```

# Resource

```bash
# Show supported resource
kubectl api-resources
# Get all resource
kubectl get all
```

* Replication Controller:
    * Manage the number and status of Pod
    * Check how many same Pods on the cluster at the same time
* Replica Set
    * Advanced version of Replication Controller
    * More flexible selector, official recommendation
* Deployment
    * Able to upgrade / downgrade version (rollout)
* Service
    * Make Pod able to communicate with outside

# Reference

* [k8s interactive tutorial](https://kubernetes.io/docs/tutorials/kubernetes-basics/create-cluster/cluster-interactive/): Learn k8s by hands-on
* [Kubernetes 30天學習筆記](https://ithelp.ithome.com.tw/users/20103753/ironman/1590): Suitable to beginners
