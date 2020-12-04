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
* [system-monitor extension](http://ubuntuhandbook.org/index.php/2019/03/display-cpu-memory-network-usage-in-ubuntu-18-04-panel/)

# File
## lsof
* `lsof <file name>`: Who open the file
* `lsof -c <command>`: List files opened by certain command
* `lsof -p <PID>`: List files opened by certain process
## zip
* `sudo apt install zip unzip`: Installation
* `zip -r file.zip folder/*`: Compress folder into file.zip
* `unzip file.zip`: Uncompress the folder

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
* Search pkg which contains certain files
  ```bash
  sudo apt install apt-file
  sudo apt update
  apt-file search <FILE_NAME>
  ```
* Disable APT daily update
  ```bash
  sudo systemctl stop apt-daily.service
  sudo systemctl stop apt-daily.timer
  sudo systemctl stop apt-daily-upgrade.service
  sudo systemctl stop apt-daily-upgrade.timer
  sudo systemctl disable apt-daily.service
  sudo systemctl disable apt-daily.timer
  sudo systemctl disable apt-daily-upgrade.service
  sudo systemctl disable apt-daily-upgrade.timer
  ```
* For error "E: Could not get lock /var/lib/dpkg/lock-frontend ...."
  ```
  sudo lsof /var/lib/dpkg/lock-frontend
  sudo kill -9 [PID]
  sudo rm -rf /var/lib/dpkg/lock-frontend
  ```
* While apt is deadlock with certain packages
  ```
  # Remove the package forcely
  sudo dpkg --ignore-depends=[pkg name] -P [pkg name]
  # Fix the apt dependency
  sudo apt --fix-broken install
  ```

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
  - `sudo systemctl restart systemd-timesyncd.service`: Restart the service and synchronize the time
    * If you don't want to use NTP, restarting the SNTP service is a good way.
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
* Driver module management
  - `sudo dkms add ./<module_src_folder>`: Add module source folder
  - `sudo dkms build -m <module_name> -v <version>`: Build kernel module
  - `sudo dkms install -m <module_name> -v <version>`: Install kernel module
  - `sudo dkms status`: Show the list of kernel module
  - `sudo dkms uninstall -m <module_name> -v <version>`: Uninstall kernel module
  - `sudo dkms remove <module_name>/<version> --all`: Remove all the kernel module source
* Hostname
  - `hostnamectl`: Show hostname
  - `hostnamectl set-hostname [new hostname]`: Modify new hostname

# Picture & Audio & Video
* Show picture from terminal
  - `eog picture.png`
* Play the video from /dev/video0
  - `mplayer tv://device=/dev/video0`: need to `sudo apt install mplayer` first
  - `vlc v4l2:///dev/video0`: need to `sudo apt install vlc` first
* Play audio
  - aplay /usr/share/sounds/xxx/xxx.wav
* Control the volume of audio
  - `sudo apt install pavucontrol`
  - `pavucontrol`

# VNC
* Install x11vnc
  - `sudo apt install x11vnc`
* Set password
  - `x11vnc -storepasswd`
* Run VNC server
  - `x11vnc -forever -usepw -display :0`
* Download [VNC viewer (Client)](https://chrome.google.com/webstore/detail/vnc%C2%AE-viewer-for-google-ch/iabmpiboiopbgfabjmgeedhcmjenhbla?utm_source=chrome-app-launcher-info-dialog) or [REAL VNC](https://www.realvnc.com/en/connect/download/viewer/)


# Desktop (tested in Ubuntu 18.04)
* `gnome-www-browser <file>`: Open file in browser
* `gnome-calculator`: Open calculator
* `gnome-terminal`: Open terminal
* `xdg-open`: Open file with GUI tools

# Disk
* Clear disk
  - `dd if=/dev/zero of=/dev/sda bs=1M status=progress`

# multipass
* Install
  - `snap install multipass`

* Run
  - Simple: `multipass launch --name myvm`
  - Assign detail: `multipass launch -c 4 -m 2048M -d 5G -n myvm`

* Info
  - List: `multipass list`
  - Info: `multipass info myvm`

* Use
  - Execute commands: `multipass exec myvm -- lsb_release -d`
  - Shell: `multipass shell myvm`

* Stop
  - Stop: `multipass stop myvm`
  - Clean: `multipass delete --purge myvm`

# Others
* Add SSH key to remote host
  - Create Key: `ssh-keygen`
  - Copy Key: `ssh-copy-id -i ~/.ssh/id_rsa.pub username@host`
* Search with filename
  - `find <PATH> -name <FILE NAME>`
* Search content from files
  - `ag <CONTENT>`
  - Should install `silversearcher-ag` first.
* Show folder size
  - `du -sh <FOLDER>`
* xargs
  - `echo a b c d e f | xargs -n 3`: Echo the first 3 items
  - `echo a b c d e f | xargs -p`: Check before execution
  - `find . -name "*.swp" | xargs rm -f -p`: Delete all the files match the search result.
  - `find . -name "*.swp" -print0 | xargs -0 rm -rf -p`: Delete all the files match the search result. (name can have space.)
  - `find . -name '*.c' | xargs grep 'main'`: Pase all the `.c` files and find main.
* Crash kernel manually
  - `sudo sh -c "echo c > /proc/sysrq-trigger"`
* Make you seem like busy
  - `sudo apt install hollywood`
  - `hollywood`
