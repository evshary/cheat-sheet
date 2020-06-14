# Network
## Address
* Show IP address
  - `ip addr show` or `ip a s`
  - IPv4/IPv6 only: `ip -4 a s` or `ip -6 a s`
* Set IP address
  - Set address: `ip a add <IP>/<NETMASK> dev <DEVICE>`
  - Clear address: `ip a del <IP>/<NETMASK> dev <DEVICE>`
* DHCP address
  - `dhclient <interface>`: Get IP address from DHCP Server
  - `dhclient -r <interface>`: Release IP address

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
* Connect/Disconnect device
  - `nmcli device connect <interface>`
  - `nmcli device disconnect <interface>`
* Network Settings
  - `nmcli device modify <interface> ipv4.method manual ipv4.addresses 10.0.0.1/8 ipv4.gateway 10.0.0.254 ipv4.dns "8.8.8.8 8.8.4.4"`
  - `nmcli device modify <interface> ipv4.method auto`
  - We can use `-` to remove setting. For example, `nmcli device modify enp1s0 -ipv4.dns 0`.
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
* cpufrequtils
  - Should install `cpufrequtils` first.
  - `cpufreq-info`: Show the status of CPU
      - You can use `cat /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor`.
  - `cpufreq-set -r -g performance -c <CPU core>`: Set CPU to performance mode
  - Easier UI tool: `sudo apt install indicator-cpufreq`
* pidstat: Show which CPU core process run on.
* i7z: Show CPU freq, temp. and turbo mode
  - `sudo apt install i7z`
  - `sudo i7z`

# File
## lsof
* `lsof <file name>`: Who open the file
* `lsof -c <command>`: List files opened by certain command
* `lsof -p <PID>`: List files opened by certain process

# Device
## Wireless Device detail
* `iwconfig`
* `iwlist`: More functions

## Ethernet Device detail
* `ethtool`

## Peripheral Device
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
  - List upgradable packages: `apt list --upgradable`
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
* Install certain version
  - Check packages version: `apt policy <PACKAGES>`
  - Install certain version: `apt install <PACKAGES>=<VERSION>`

## dpkg
* Show deb info
  - `dpkg --info xxxx.deb`
* Show what will be installed
  - `dpkg -c xxxx.deb`

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

## nvm/npm
* nvm is the version controller of npm, so should install first.
  - `curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.35.3/install.sh | bash`
  - You should view [the github](https://github.com/nvm-sh/nvm) and get the newest version.
* nvm:
  - List version: `nvm list`
  - List available version: `nvm list available`
  - Install version: `nvm install <version>`
  - Use certain version: `nvm use <version>`
* npm:
  - Init project and create package.json: `npm init`
    * description and repo url should not be empty.
  - Install package: `npm install <package name>`
    * Will create 3 files: `package.json` and `package-lock.json` should be controlled by git and `node_modules` should be ignored.
    * Install package and save into package.json: `npm install <package name> --save`
  - Restore dependy while git clone from repo: `npm install`
  - Uninstall package: `npm uninstall <package name>`
    * Uninstall package and save into package.json: `npm uninstall <package name> --save`

# Debug
* Emulate stress status
  - CPU: `stress --cpu N`
  - Memory(2 workers alloc/free 1GB): `stress --vm 2 --vm-bytes 1G`
  - IO: `stress --io N`

# System
* Update system time with NTP
  - `ntpdate <NTP Server>`
  - `ntpdate time.stdtime.gov.tw`
* System time
  - `timedatectl`: Show system and RTC time
  - `sudo systemctl restart systemd-timesyncd.service`: Restart the service adn synchronize the time
  - `timedatectl list-timezones`: List the timezone
  - `timedatectl set-timezone Asia/Taipei`: Set the timezone
* Save local time into RTC (If you use Windows and Linux in the same machine, it's necessary for time sync)
  - `sudo hwclock --localtime --systohc`
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
* Change directory history
  - `pushd <directory>`: Push the current directory.
  - `dirs -p -v`: Show directory stack.
  - `dirs -c`: Clear directory stack.
  - `popd`: Pop the latest directory.
  - `pushd +N`: Choose the directory.
* Open file manager from terminal
  - `xdg-open .`: Open file manager.
* Driver module management
  - `sudo dkms add ./<module_src_folder>`: Add module source folder
  - `sudo dkms build -m <module_name> -v <version>`: Build kernel module
  - `sudo dkms install -m <module_name> -v <version>`: Install kernel module
  - `sudo dkms status`: Show the list of kernel module
  - `sudo dkms uninstall -m <module_name> -v <version>`: Uninstall kernel module
  - `sudo dkms remove <module_name>/<version> --all`: Remove all the kernel module source

# Audio&Video
* Play the video from /dev/video0
  - `mplayer tv://device=/dev/video0`: need to `sudo apt install mplayer` first
  - `vlc v4l2:///dev/video0`: need to `sudo apt install vlc` first
* Play audio
  - aplay /usr/share/sounds/xxx/xxx.wav
* Control the volume of audio
  - `sudo apt install pavucontrol`
  - `pavucontrol`

# Others
* Search with filename
  - `find <PATH> -name <FILE NAME>`
* Search content from files
  - `ag <CONTENT>`
  - Should install `silversearcher-ag` first.
* Show folder size
  - `du -sh <FOLDER>`
