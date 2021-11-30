# Introduction

cgroup can group the process and do resource allocation.

Functions:
* Resource limitation
* Prioritization
* Accounting: for statistics
* Control: stop / start process

cgroup contains the following parts:
* task: task is process
* cgroup: the basic unit for resource control
* subsystem: also called resource controller, like CPU, memory...
* hierarchy: each hierarchy means a cgroup tree, which is related to the specific subsystem

# Usage

* Check whether Linux enables cgroup or not: 
```bash
cat /boot/config-`uname -r` | grep CGROUP
```
* List all subsystems:
  - `ls /sys/fs/cgroup`
  - `mount | grep cgroup`
* List the subsystem and the detail info: `cat /proc/cgroups`
* Show the PID belongs to which cgroup: `cat /proc/<pid>/cgroup`
* Get the configuration of the cgroup
  - `cat /sys/fs/<subsystem>/<configuration>`
  - i.e. `cat /sys/fs/cgroup/cpu,cpuacct/cpu.cfs_period_us`

# Binary for cgroups

* Installation:
```bash
sudo apt install cgroup-tools
```
* Create cgroup
```bash
cd /sys/fs/cgroup/cpu
sudo mkdir nick_cpu
# Include the configuration inherited from cpu
ls /sys/fs/cgroup/cpu/nick_cpu
```
* Set the configuration
```bash
sudo su
echo 100000 > nick_cpu/cpu.cfs_period_us
echo 10000 > nick_cpu/cpu.cfs_quota_us
```
* Build the cpu test program
```bash
make
sudo su
time ./cpu.out
time cgexec -g cpu:nick_cpu ./cpu.out
```

# Reference

* [Linux Cgroup 入门教程：基本概念](https://fuckcloudnative.io/posts/understanding-cgroups-part-1-basics/#span-idinline-toc4span-%E6%80%BB%E7%BB%93): basic concept of cgroup
* [Linux cgroup詳解（理論與實例）](https://www.twblogs.net/a/5d164e92bd9eee1ede05419a): basic concept of cgroup and the detail subsystem parameters for setting
* [第一千零一篇的 cgroups 介紹](https://medium.com/starbugs/%E7%AC%AC%E4%B8%80%E5%8D%83%E9%9B%B6%E4%B8%80%E7%AF%87%E7%9A%84-cgroups-%E4%BB%8B%E7%B4%B9-a1c5005be88c): include the history of cgroup v1/v2
* [linux cgroups 简介](https://cloud.tencent.com/developer/article/1444877): Contains the experiment of how to use cgroup
