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

# kubeadm & kubelet

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

# k3s

![image](https://user-images.githubusercontent.com/456210/199198288-64cdc1ae-bd0d-4b95-a35f-00fefaafb33e.png)

[image src](https://k3s.io/)

* Install k3s as a service
  - Refer to [here](https://github.com/k3s-io/k3s#quick-start---install-script)

```bash
# Install
curl -sfL https://get.k3s.io | sh -
# Check settings
k3s check-config
# Test
sudo k3s kubectl version
# Uninstall
k3s-uninstall.sh
```

* Note: you need to add k3s for kubectl commands


# Reference

* [k8s interactive tutorial](https://kubernetes.io/docs/tutorials/kubernetes-basics/create-cluster/cluster-interactive/): Learn k8s by hands-on
* [Kubernetes 30天學習筆記](https://ithelp.ithome.com.tw/users/20103753/ironman/1590): Suitable to beginners
