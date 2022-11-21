# File
## lsof
* `lsof <file name>`: Who open the file
* `lsof -c <command>`: List files opened by certain command
* `lsof -p <PID>`: List files opened by certain process
## zip
* `sudo apt install zip unzip`: Installation
* `zip -r file.zip folder/*`: Compress folder into file.zip
* `unzip file.zip`: Uncompress the folder

# Packages
## dpkg
* Show deb info
  - `dpkg --info xxxx.deb`
* Show what will be installed
  - `dpkg -c xxxx.deb`
* Extract deb file
  - `dpkg -x xxxx.deb <output directory>`

## Chocolatey
* List packages
  - List all packages: `choco list`
  - List installed packages: `choco list --local-only`
  - Search packages: `choco search <PACKAGES>`
  - Search packages contains string: `choco search ros-melodic-`
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

# Picture & Video
* Show picture from terminal
  - `eog picture.png`
* Play the video from /dev/video0
  - `mplayer tv://device=/dev/video0`: need to `sudo apt install mplayer` first
  - `vlc v4l2:///dev/video0`: need to `sudo apt install vlc` first
* Check the resolution & FPS of camera
```bash
sudo apt-get install v4l-utils
v4l2-ctl --list-formats-ext
```

## graphic
* mesa-utils:
  - Show whether the system support "direct rendering"
    - `glxinfo | grep "direct rendering"`
  - Test FPS of the graphic
    - `glxgears`
* read-edid:
  - Read edid of display equipment
    - `sudo get-edid | parse-edid`

# VNC
* Install x11vnc
  - `sudo apt install x11vnc`
* Set password
  - `x11vnc -storepasswd`
* Run VNC server
  - `x11vnc -forever -usepw -display :0`
* Download [VNC viewer (Client)](https://chrome.google.com/webstore/detail/vnc%C2%AE-viewer-for-google-ch/iabmpiboiopbgfabjmgeedhcmjenhbla?utm_source=chrome-app-launcher-info-dialog) or [REAL VNC](https://www.realvnc.com/en/connect/download/viewer/)

# Desktop (tested in Ubuntu 20.04)
* `gnome-www-browser <file>`: Open file in browser
* `gnome-calculator`: Open calculator
* `gnome-terminal`: Open terminal
* `gnome-power-statistics`: View power estimation
* `xdg-open`: Open file with GUI tools
  - `xdg-open .`: Open the current folder
* `gtk-launch xxx.desktop`: Run desktop application in CLI
  - Note that you need to change the directory to the destination.
  - For more limitation: https://unix.stackexchange.com/questions/393079/gtk-launch-only-works-when-present-working-directory-is-desktop

# input
Need to install `input-utils`

* List input device: `sudo lsinput`
  - The same as viewing `/proc/bus/input/devices`
  - Get brief name: `sudo lsinput | grep name`
* Detect event from input: `sudo input-events <number>`
  - Mouse / keyboard are both OK.
* Detect keyboard press / release: `sudo showkey`

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

# SSH
* Add SSH key to remote host
  - Create Key: `ssh-keygen`
  - Copy Key: `ssh-copy-id -i ~/.ssh/id_rsa.pub username@host`
* Connect SSH with graphic
  - `ssh -X <IP>`
* Connect SSH with forwarding SSH agent
  - `ssh -A <IP>`

# nohup
Make sure the program can continue running while the session exits (ssh).
That is, ignore SIGHUP signal after session exits

* Run: `nohup ./myprogram &`
* See output: 
  - `cat nohup.txt`
  - Assign filename: `nohup ./myprogram &> mylog.txt &`
  - Separate normal & error message: `nohup ./myprogram > my.log 2> my.err &`

# Others
* Search with filename
  - `find <PATH> -name <FILE NAME>`
* Search content from files
  - `ag <CONTENT>`
  - Should install `silversearcher-ag` first.
* Show folder size
  - `du -sh <FOLDER>`
* List the largest file under the path
  - Include directories: `du -ah * | sort -rh | head -n 10`
  - Ignore directories: `find . -type f -exec du -ah {} + | sort -rh | head -n 10`
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
* View ACPI event(Volume up/down, power button)
  - `acpi_listen`
* Show power status
  - `upower -d`
* Show "Device is busy" while umount
  -  `fuser -m <folder_name>` will show which processes use the folder.
