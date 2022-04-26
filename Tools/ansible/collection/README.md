# collection

Able to package playbook, roles, modules, plugins into collection and upload to Ansible Galaxy for others to download.

# Usage

* Init collection

```bash
ansible-galaxy collection init my_namespace.my_colletion
```

* Modify `galaxy.yml` for brief description

* Put your playbook, roles, plugins into each folder.

* Install collection

```bash
// install collection
ansible-galaxy install -f -r ansible-galaxy-requirements.yaml
// my_collection appears
ansible-galaxy collection list | grep my_collection
```

* Run collection

```bash
ansible-playbook my_namespace.my_collection.your_playbook --ask-become-pass
```

# Reference

* [如何貢獻你的第一支 Ansible Collection 以及 Ansible Tower Workflow 應用簡介](https://hazel.style/2021/05/28/How-to-contribute-your-first-Ansible-Collection-and-Ansible-Tower-Workflow-Use-Case/)