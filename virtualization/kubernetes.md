# Introduction

Kubernetes is a system which can help us deploy / manage containerized application.

* Deploy multiple container to multipe machines
* Manage the status of containers
* Transfer containers between machines
* Scalability: from one machine to multiple machines

# Architecture

![image](https://user-images.githubusercontent.com/456210/199143294-7f75cf8b-dc52-4a11-8ed0-a411461b9fa6.png)

[image src](https://medium.com/devops-mojo/kubernetes-architecture-overview-introduction-to-k8s-architecture-and-understanding-k8s-cluster-components-90e11eb34ccd)

![image](https://user-images.githubusercontent.com/456210/199143464-4c1551ed-b626-4077-9b08-3826827c496a.png)

[image src](https://blog.octo.com/how-does-it-work-kubernetes-episode-1-kubernetes-general-architecture/)

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

# minikube

![image](https://user-images.githubusercontent.com/456210/199153222-ce54e34d-7aac-475a-95f8-67a3e95f9f2e.png)

[image src](https://www.armosec.io/blog/setting-up-kubernetes-cluster/)

[Official Website](https://minikube.sigs.k8s.io/docs/start/)

Able to create k8s cluster

```bash
# Enable cluster
minikube start
# Check status
minikube status
# Verify
kubectl version
# Stop
minikube stop
```

# kubeadm

![image](https://user-images.githubusercontent.com/456210/199153268-2ec1192d-3436-4c03-ac7e-56aef68c6f22.png)

[image src](https://www.armosec.io/blog/setting-up-kubernetes-cluster/)

* Install: refer to [here](https://kubernetes.io/docs/setup/production-environment/tools/kubeadm/install-kubeadm/#installing-kubeadm-kubelet-and-kubectl)

```bash
# https://kubernetes.io/docs/reference/setup-tools/kubeadm/kubeadm-init/
# first machine
kubeadm init
# second machine
kubeadm join
```

There are many tricky parts while installation, so you can refer to [here](https://tree.rocks/kubernetes-with-multi-server-node-setup-on-ubuntu-server-280066e6b106)

# kubectl

* [installation](https://kubernetes.io/docs/tasks/tools/install-kubectl-linux/)
* [cheat-sheet](https://kubernetes.io/docs/reference/kubectl/cheatsheet/)

Used to control k8s cluster

## Basic operation

* View global config

```bash
kubectl config view
```

* View & find resources

```bash
# nodes
kubectl get nodes -o wide # List node with detail
# pod
kubectl get pods -o wide # List all pods with detail in current namspace
kubectl get pods -A      # List all pods in all namepsaces
kubectl get pods <pod_name> -o yaml # Get pod's YAML
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

## create & apply YAML

Create from YAML

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

## Interact with pod

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

## Debug

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

## Resource

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
