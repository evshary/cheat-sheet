# Useful command

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
* Download packages
  - Download: `apt download <PACKAGES>`
* Upgrade packages
  - Upgrade all: `apt upgrade`
  - Upgrade certain: `apt install <PACKAGES>`
  - Only upgrade packages: `apt --only-upgrade install <PACKAGES>`
  - Only upgrade ROS foxy packages: `apt --only-upgrade install "^ros-foxy-*"`
* Install certain version
  - Check packages version: `apt policy <PACKAGES>`
  - Install certain version: `apt install <PACKAGES>=<VERSION>`
* Search pkg which contains certain files
  ```bash
  sudo apt install apt-file
  sudo apt update
  apt-file search <FILE_NAME>
  ```

# Key operation

The key will be in `/etc/apt/trusted.gpg` or under `/etc/apt/trusted.gpg.d/`

* Add key: `wget -qO - https://www.aptly.info/pubkey.txt | sudo apt-key add -`
* List key: `sudo apt-key list`
* Delete key: `sudo apt-key del <the_last_8_bytes_ID>`
* Advanced option:
  - Get key from key server: `sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv 9DA31620334BD75D9DCB49F368818C72E52529D4`

# How to add new repository

## Add from source.list 

* Edit `/etc/apt/source.list`
  - You need to add key for the source repo, or need to add `[trusted=yes]`
* If you want to use CLI tools instead
```bash
# It'll be put into /etc/apt/source.list
sudo add-apt-repository 'deb [arch=amd64] https://repo.mongodb.org/apt/ubuntu bionic/mongodb-org/4.0 multiverse'
# If you want to remove
sudo add-apt-repository --remove 'deb [arch=amd64] https://repo.mongodb.org/apt/ubuntu bionic/mongodb-org/4.0 multiverse'
```
* source.list format: `[deb/deb-src] [URL] [Ubuntu version] [Type]`
  - Example: `deb [trusted=yes] http://website:8080/common/ focal main`
  - deb/deb-src
    - deb:binary, deb-src:source code
  - URL
    - Download URL
  - Ubuntu version
    - 18.04:bionic, 20.04:focal
  - Type

|            | Free Software | Not Free Software |
|    -       |       -       |         -         |
| Official   | Main          | Restricted        |
| Unofficial | Universe      | Multiverse        |

## Add from Launchpad PPA

PPA: Personal Package Archives

You can upload your package to PPA, and others can apt install from your PPA repo.
You don't need to add key by yourself.

https://launchpad.net/ubuntu/+ppas

### Usage

* Add PPA
  - The PPA will be stored under `/etc/apt/sources.list.d/`
  - Remember to run `apt update` after adding PPA
```bash
# sudo add-apt-repository ppa:<user_name>/<ppa_name>
sudo add-apt-repository ppa:nginx/stable
```

* Remove PPA
```bash
# sudo add-apt-repository --remove ppa:<user_name>/<ppa_name>
sudo add-apt-repository --remove ppa:nginx/stable
```

# Scenario

* Switch APT server
  - Find the appropriate apt server here: https://launchpad.net/ubuntu/+archivemirrors
  - Use vim to open and change the server by regular expression: `:%s/http:\/\/archive.ubuntu.com\/ubuntu/http:\/\/free.nchc.org.tw\/ubuntu/g`
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

