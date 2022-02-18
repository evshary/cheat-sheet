# ansible

ansible can manage your device easily.

# Installation

* Use apt. It seems like install from python-pip may cause some problems.

```bash
sudo apt install ansible
```

# Files

There are 3 important files in ansible

* ansible.cfg: default config
* hosts inventory: host list
* your_playbook.yml: what thing you want to do

You can refer to the architecture from [IBM blog](https://www.ibm.com/cloud/blog/end-to-end-application-provisioning-with-ansible-and-terraform).

![](https://1.cms.s81c.com/sites/default/files/2018-11-22/Ansible_ov.png)

# Two modes

There are two modes in ansible Ad-Hoc and Playbook.

* Ad-Hoc
  - Connect to localhost and run command.

```bash
ansible localhost -m command -a 'echo Hello World.'
```

* Playbook

```bash
ansible-playbook xxx.yml
```

# Reference

* [Ansible Documentation](https://docs.ansible.com/ansible/latest/index.html)
* [現代 IT 人一定要知道的 Ansible 自動化組態技巧](https://chusiang.gitbooks.io/automate-with-ansible/content/)
* [幾個小建議改善你的 Ansible 技能](https://blog.pichuang.com.tw/20180622-suggestions_to_improve_your_ansible_playbook/)
