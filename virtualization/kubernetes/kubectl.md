# kubectl

Used to control k8s cluster

* [cheat-sheet](https://kubernetes.io/docs/reference/kubectl/cheatsheet/)

# Installation

You can [install with k8s](https://kubernetes.io/docs/tasks/tools/install-kubectl-linux/)

But if you use k3s / minikube, they also have their own kubectl, but you might need to start with `k3s kubectl` or `minikube kubectl`.

# Basic operation

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

# create & apply YAML

* Create YAML

```yaml
# pod.yaml
---
apiVersion: v1   # Use v1 API
kind: Pod        # Kind is Pod
metadata:        # Name Pod as myname, and add lable app:web
  name: myname
  labels:
    app: web
spec:                    # Describe spec
  containers:            # Describe container
  - name: myfrontend     # Name container as myfrontend
    image: nginx         # Use image nginx
    ports:
    - containerPort: 80  # Use port 80
```

* Run based on YAML

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

# Interact with pod

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

# Debug

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
