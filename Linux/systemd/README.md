# What is systemd

systemd is "system and service manager" in Linux.

There are several commands tool set in systemd, like systemctl, systemd-analyze, hostnamectl, localectl, timedatectl, loginctl.

# Useful command

## Manage service
* `systemctl`: List all the activated service.
* `systemctl --all`: List all the service.
* `systemctl start xxx`: Start a service.
* `systemctl stop xxx`: Stop a service.
* `systemctl status xxx`: Show the status of the service.
* `systemctl enable xxx`: Start a service while bootup.
* `systemctl disable xxx`: Stop a service while bootup.
* `systemctl daemon-reload`: Reload systemd and regenerate the Unit dependency tree.

## Log service
* `journalctl -u xxx`: See the log of service.
* `journalctl --user -u xxx`: See the log of user serivce.
* `journalctl -u xxx -b -0`: See the last time log of xxx. `-0` can be replaced with other number.

## Bootup analyze
* `systemd-analyze`: Lookup the bootup time.
* `systemd-analyze blame`: Anaylze the bootup time for each service.
* `systemd-analyze critical-chain`: Show bootup time in waterfall way.
* Add `--user` to view user service. For example, `systemd-analyze --user critical-chain`

## Session manager
* `loginctl list-sessions`: List all the current sessions
* `loginctl list-users`: List all the current login user
* `loginctl user-status`: Show the running process of login user
* `loginctl show-user`: Show login user parameters

Refer to [manual](http://manpages.ubuntu.com/manpages/bionic/zh_TW/man1/loginctl.1.html) for more detail.

# How to execute specific command while bootup

* Create a file under `/etc/systemd/system/`, for example: `/etc/systemd/system/myprog.service`

```
[Unit]
Description=myprog description
Requires=network.target

[Service]
ExecStart=/path/to/myprog

[Install]
WantedBy=multi-user.target
```

* Then enable the service.

```bash
systemctl enable myprog
```

* After reboot, see the running status

```bash
# See all the running service
systemctl status
# See the status of myprog
systemctl status myprog
```

# Run specific command with user privilege

* Make sure the user systemd can run without login
  - See whether the user systemd is running or not: `systemctl status user-1000.slice` and `systemctl --user status`
  - If the user is not linger, user systemd will not run before login
  - Refer to https://superuser.com/questions/1561076/systemctl-use-failed-to-connect-to-bus-no-such-file-or-directory-debian-9

```bash
# Make sure user service will start no matter login or not
loginctl enable-linger <your-username>
# Will create user name file under `/var/lib/systemd/linger`, you can also view by `loginctl user-status | grep Linger`
```

* Put the `myprog.service` file under `~/.config/systemd/user`
  - Note the `WantedBy target` can get from `systemctl --user --type=target`

```
[Unit]
Description=myprog description
After=network-online.target
Wants=network-online.target

[Service]
Type=idle
ExecStart=/path/to/myprog
RemainAfterExit=yes

[Install]
WantedBy=default.target
```

* Then enable the service
  - It'll create a symbolic link to `~/.config/systemd/user/multi-user.target.wants/`.

```bash
systemctl enable --user myprog
```

* After reboot, see the running status

```bash
# See all the running user service
systemctl status --user
# See the status of myprog
systemctl status --user myprog
```

* Note: if you want to control other non-login user systemd

```bash
# Make sure /run/user/<USER ID> is available
loginctl enable-linger <USER_NAME>
# Add environmental variable to run systemctl command
sudo -H -u <USER_NAME> bash -c 'export XDG_RUNTIME_DIR=/run/user/<USER ID>; systemctl --user'
```

# Reference

* [systemd from archlinux](https://wiki.archlinux.org/index.php/Systemd)
* [Systemd 入门教程：命令篇](http://www.ruanyifeng.com/blog/2016/03/systemd-tutorial-commands.html)
* [linux systemctl 命令](https://www.cnblogs.com/sparkdev/p/8472711.html)
