# install
* Use apt. It seems like install from python-pip may cause some problems.
```
sudo apt install ansible
```

# Files
There are 3 files in the directory:

* ansible.cfg: default config
* hosts inventory: host list
* your_playbook.yml: what thing you want to do

You can refer to the architecture from [IBM blog](https://www.ibm.com/cloud/blog/end-to-end-application-provisioning-with-ansible-and-terraform).

![](https://1.cms.s81c.com/sites/default/files/2018-11-22/Ansible_ov.png)

# Usage
* Create `ansible.cfg`. `inventory = hosts` assign the inventory name.
```
[defaults]
inventory = hosts
```
* Create `hosts` for host inventory.
```
[YOUR_HOSTS]
<IP>

[YOUR_HOSTS:vars]
ansible_password=<pass>
ansible_become_pass=<pass>
ansible_ssh_user=<user>
host_key_checking=False
ansible_python_interpreter=/usr/bin/python3
```
* List the current host status.
```
# List inventory settings
ansible-inventory --list -y
# List hosts
ansible all --list-hosts
```
* Test
```
ansible YOUR_HOSTS -m ping
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

# Reference
* [Ansible Documentation](https://docs.ansible.com/ansible/latest/index.html)
* [現代 IT 人一定要知道的 Ansible 自動化組態技巧](https://chusiang.gitbooks.io/automate-with-ansible/content/)
