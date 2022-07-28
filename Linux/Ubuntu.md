# User Account

* Not to show user in login page:
  - `cd /var/lib/AccountsService/users`
  - Find your username and open it.
  - Modfiy `SystemAccount` from true to false.

# Ubuntu kernel

You can use GUI to maintain Ubuntu kernel version

* Installation

```bash
sudo add-apt-repository ppa:cappelikan/ppa
sudo apt update
sudo apt install mainline
```

* Add/Remove kernel: Open `mainline` application from launchpad.

* Update `/etc/default/grub` to select the kernel.
  - Comment the `GRUB_TIMEOUT_STYLE=hidden` and set `GRUB_TIMEOUT=10`
  - Run `sudo update-grub`
