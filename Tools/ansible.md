# install
```
sudo apt install ansible
```

# Files
There are 3 files in the directory:

* ansible.cfg: default config
* inventory: host list
* your_playbook.yml: what thing you want to do

# Usage
* Create `ansible.cfg`
```
[defaults]
inventory = ./inventory
```
* Create `inventory` for host infomation
```
[ROS2]
<IP>

[ROS2:vars]
ansible_password=<pass>
ansible_become_pass=<pass>
ansible_ssh_user=<user>
host_key_checking=False
ansible_python_interpreter=/usr/bin/python3
```
* List the current status
```
# List inventory settings
ansible-inventory --list -y
# List hosts
ansible all --list-hosts
```
* Test
```
ansible ROS2 -m ping
```
* Create playbook "your_playbook.yml"
```
---
- hosts: YOUR_HOSTS
  become: true  # use sudo
  tasks:
    - name: Install vim
      apt: name=vim update_cache=yes state=latest
    - name: Get date
      shell: date
```
* Run playbook
```
ansible-playbook your_playbook.yml
```
