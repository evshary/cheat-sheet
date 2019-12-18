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

## Network Manager
* Enable/Disable Network Mangager
  - `nmcli networking on`
  - `nmcli networking off`
* Show network device status
  - `nmcli device status`
* Show detail device info
  - `nmcli device show`
* Show connection record
  - `nmcli connection show`
* Show wireless signal
  - `nmcli device wifi`
* Connect to SSID
  - `nmcli device wifi connect <SSID> password <password>`
  - Connection infomation will be in `/etc/NetworkManager/system-connections/<SSID>`
* Connect/disconnect to SSID already known
  - `nmcli connection show` to get UUID
  - `nmcli connection up <UUID>`
  - `nmcli connection down <UUID>`

# CPU
* Should install `cpufrequtils` first.
* `cpufreq-info`: Show the status of CPU
  - You can use `cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor`.
* `cpufreq-set -r -g performance -c <CPU core>`: Set CPU to performance mode
  

# Wireless Device detail
* `iwconfig`
* `iwlist`: More functions

# Peripheral Device
* List device info
  - Hardware: `lshw`
  - CPU: `lscpu`
  - USB: `lsusb`
  - PCI: `lspci`
  - Block devices: `lsblk`
  - Memory: `lsmem`
* List the disk
  - `df -h`

# Packages
## apt
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

## Chocolatey
* List packages
  - List all packages: `choco list`
  - List installed packages: `choco list --local-only`
  - Search packages: `choco search <PACKAGES>`
* Install/Uninstall packages
  - Install: `choco install <PACKAGES>`
  - Uninstall: `choco uninstall <PACKAGES>`
* Upgrade packages
  - Upgrade all: `choco upgrade all`
  - Upgrade certain: `choco upgrade <PACKAGES>`
  - Upgrade all except: `choco upgrade all --except="'<PACKAGES>,<PACKAGES>'"`

# Debug
* Emulate stress status
  - CPU: `stress --cpu N`
  - Memory(2 workers alloc/free 1GB): `stress --vm 2 --vm-bytes 1G`
  - IO: `stress --io N`

# System
* Update system time with NTP
  - `ntpdate <NTP Server>`
  - `ntpdate time.stdtime.gov.tw`
* Change default program (editor...)
  - `update-alternatives --display <COMMAND>`: List all candidates for certain command.
  - `sudo update-alternatives --config <COMMAND>`: Select which program we use in default.
  - `update-alternatives --install <LINK> <NAME> <PATH> <PRIORITY>`: Add option for certain command.
    * LINK: command absolute directory
    * NAME: command
    * PATH: real program absolute directory
    * PRIORITY
    * e.g. `update-alternatives --install /usr/bin/vim vim /usr/bin/vim.basic 1000`
  - `update-alternatives --remove <NAME> <PATH>`: Remove option for certain command.

# Others
* Search with filename
  - `find <PATH> -name <FILE NAME>`
* Search content from files
  - `ag <CONTENT>`
  - Should install `silversearcher-ag` first.
* Show folder size
  - `du -sh <FOLDER>`
