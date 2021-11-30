# What is systemd

systemd is "system and service manager" in Linux.

There are several commands tool set in systemd, like systemctl, systemd-analyze, hostnamectl, localectl, timedatectl, loginctl.

# Architecture

This figure is from https://www.3chy2.com.tw/3c%E8%B3%87%E8%A8%8A/linux-systemd-%E8%A9%B3%E7%B4%B0%E4%BB%8B%E7%B4%B9-unit%E3%80%81unit-file%E3%80%81systemctl%E3%80%81target/

![](https://www.3chy2.com.tw/wp-content/uploads/2020/09/2b6e63f55d7877e7ea440ccdcd24ad95.jpg)

# Unit File

The basic concept of systemd is unit. There are several types of unit.

The table is from https://www.3chy2.com.tw/3c%E8%B3%87%E8%A8%8A/linux-systemd-%E8%A9%B3%E7%B4%B0%E4%BB%8B%E7%B4%B9-unit%E3%80%81unit-file%E3%80%81systemctl%E3%80%81target/

| Type | filename extention | Description |
| - | - | - |
| Service |	.service | 封裝守護進程的啟動、停止、重啟和重載操作，是最常見的一種 Unit 文件 |
| Target | .target | 定義 target 信息及依賴關係，一般僅包含 Unit 段 |
| Device | .device | 對於 /dev 目錄下的硬件設備，主要用於定義設備之間的依賴關係 |
| Mount | .mount | 定義文件系統的掛載點，可以替代過去的 /etc/fstab 配置文件 |
| Automount | .automount | 用於控制自動掛載文件系統，相當於 SysV-init 的 autofs 服務 |
| Path | .path | 用於監控指定目錄或文件的變化，並觸發其它 Unit 運行 |
| Scope | .scope | 這種 Unit 文件不是用戶創建的，而是 Systemd 運行時產生的，描述一些系統服務的分組信息 |
| Slice | .slice | 用於表示一個 CGroup 的樹 |
| Snapshot | .snapshot | 用於表示一個由 systemctl snapshot 命令創建的 Systemd Units 運行狀態快照，可以切回某個快照 |
| Socket | .socket | 監控來自於系統或網絡的數據消息 |
| Swap | .swap | 定義一個用戶做虛擬內存的交換分區 |
| Timer | .timer | 用於配置在特定時間觸發的任務，替代了 Crontab 的功能 |

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
* `journalctl --verify`: Verify the log completion.
* `journalctl --disk-usage`: Show the log usage.

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

* [Linux Systemd 詳細介紹: Unit、Unit File、Systemctl、Target](https://www.3chy2.com.tw/3c%E8%B3%87%E8%A8%8A/linux-systemd-%E8%A9%B3%E7%B4%B0%E4%BB%8B%E7%B4%B9-unit%E3%80%81unit-file%E3%80%81systemctl%E3%80%81target/)
* [systemd from archlinux](https://wiki.archlinux.org/index.php/Systemd)
* [Systemd 入门教程：命令篇](http://www.ruanyifeng.com/blog/2016/03/systemd-tutorial-commands.html)
* [linux systemctl 命令](https://www.cnblogs.com/sparkdev/p/8472711.html)
