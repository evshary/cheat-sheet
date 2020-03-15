# What is systemd

systemd is "system and service manager" in Linux.

# Useful command

* `systemctl`: List all the activated service.
* `systemctl --all`: List all the service.
* `systemctl start xxx`: Start a service.
* `systemctl stop xxx`: Stop a service.
* `systemctl status xxx`: Show the status of the service.
* `systemctl enable xxx`: Start a service while bootup.
* `systemctl disable xxx`: Stop a service while bootup

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

```
systemctl enable myprog
```

# Reference

* [systemd from archlinux](https://wiki.archlinux.org/index.php/Systemd)
