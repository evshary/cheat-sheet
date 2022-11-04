# How to clean disk

This tutorial guides you how to clean your disk space.

# Analysis

* Use `lsblk` or `df -h` to get the total disk space.
* Use `qdirstat` to analyze disk usage.

# Clean

* Empty trash
* Clear chrome cahce
* Empty vscode cache: `rm -rf ~/.config/Code/User/workspaceStorage/*`

## apt

* Clean unused dependency packages:

```bash
sudo apt autoremove
```

* While dpkg install deb, deb files will put under `/var/cache/apt/archives/`

```bash
# Clean all deb files
apt clean
# Only clean outdated deb files
apt autoclean
```

## log

```bash
# Mark current log as archived
sudo journalctl --rotate
# Delete log until size is smaller than 100M
sudo journalctl --vacuum-size=100M
# Edit /etc/systemd/journald.conf and modify SystemMaxUse=100M
# Reload daemon
sudo systemctl daemon-reload
```

## swap

```bash
# Check the current swap size
free -h
# Remove the current swapfile
sudo swapoff /swapfile
sudo rm /swapfile
# Create a new swapfile with smaller size
sudo fallocate -l 4G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
```

## docker

```bash
# Remove unused docker images
sudo docker rmi <image ID>
# Clear
docker system prune
docker system prune -a --volume
```

## snap

```bash
# Show snap list
snap list
# Remove unused snap
sudo snap remove --purge <snap name>
# Clear cache
sudo sh -c 'rm -rf /var/lib/snapd/cache/*'
```
