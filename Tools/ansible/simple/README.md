# simple

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

```bash
# List inventory settings
ansible-inventory --list -y
# List hosts
ansible all --list-hosts
```

* Test

```bash
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

```bash
ansible-playbook your_playbook.yml
```
