# Network
## Address
* Show IP address
  - `ip addr show` or `ip a s`
  - IPv4/IPv6 only: `ip -4 a s` or `ip -6 a s`
* Set IP address
  - Set address: `ip a add <IP>/<NETMASK> dev <DEVICE>`
  - Clear address: `ip a del <IP>/<NETMASK> dev <DEVICE>`

## Router
* Show router
  - `ip route` or `ip r` 
* Set default router
  - `ip r add default via <GATEWAY> dev <DEVICE>`
* Set routing table
  - `ip route add <IP>/<NETMASK> via <GATEWAY> dev <DEVICE>`
  - `ip route del <IP>/<NETMASK>`

## Interface
* Only show MAC
  - `ip link show`
  - Show the running interface: `ip link show up`
* Turn on/off network interface
  - `ip link set <DEVICE> up`
  - `ip link set <DEVICE> down`

## Socket Status
* List all the socket status
  - `ss`
* Only list certain socket
  - Listening port: `ss -l`
  - TCP socket: `ss -t`
  - UDP socket: `ss -u`
  - Domain socket: `ss -x`

# Peripheral Device
* List all USB device
  - `lsusb`
* List all PCI device
  - `lspci`
* List the disk
  - `df -h`

# Packages - apt
* Update source list
  - `apt update`
* List packages
  - List all packages: `apt list`
  - List installed packages: `apt list --installed`
  - Search packages: `apt search <PACKAGES>`
  - Show packages: `apt show <PACKAGES>`
* Install/Uninstall packages
  - Install: `apt install <PACKAGES>`
  - Uninstall: `apt remove <PACKAGES>`
  - Uninstall(Including config): `apt purge <PACKAGES>`
* Upgrade packages
  - Upgrade all: `apt upgrade`
  - Upgrade certain: `apt install <PACKAGES>`
  - Only upgrade packages: `apt --only-upgrade install <PACKAGES>`

# System
* Update system time with NTP
  - `ntpdate <NTP Server>`
  - `ntpdate time.stdtime.gov.tw`

# Others
* Search with filename
  - `find <PATH> -name <FILE NAME>`
* Search content from files
  - `ag <CONTENT>`
  - Should install `silversearcher-ag` first.
* Show folder size
  - `du -sh <FOLDER>`
