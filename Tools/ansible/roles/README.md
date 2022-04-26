# roles

Ansible can reuse others' playbook by `roles`, just like pip install in Python.

The list of roles are in [galaxy](https://galaxy.ansible.com/)

# Usage

* Use ansible-galaxy to download

```bash
# search roles
ansible-galaxy search yatesr.timezone
# install roles, installed under ~/.ansible
ansible-galaxy install yatesr.timezone
# (optional) install locally
# ansible-galaxy install --roles-path roles yatesr.timezone
# list installed roles
ansible-galaxy list
# remove
ansible-galaxy remove yatesr.timezone
```

* (Optional) Use requirements.yml to install roles

```bash
ansible-galaxy install -f -p roles -r requirements.yml
```

* Run

TODO: I can't run the playbook currently, maybe due to [this issue](https://github.com/ansible/ansible/issues/70772)

```bash
ansible-playbook -vvv your_playbook.yml
```
