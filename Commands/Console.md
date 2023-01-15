# VNC
## Server

### tigervnc (Able to login without display)

* Install ubuntu gnome desktop
  - `sudo apt install ubuntu-gnome-desktop`
* Install tigervnc
  - `sudo apt install tigervnc-standalone-server`
* Update passwd
  - `vncpasswd`
* Create `~/.vnc/xstartup`

```shell
#!/bin/sh
# Start Gnome 3 Desktop
[ -x /etc/vnc/xstartup ] && exec /etc/vnc/xstartup
[ -r $HOME/.Xresources ] && xrdb $HOME/.Xresources
vncconfig -iconic &
dbus-launch --exit-with-session gnome-session &
```

* Start the server (Open port in 5900 + <:no>, e.g. `:1` means 5901)
  - `vncserver -localhost no <:no>`
  - e.g. `vncserver -localhost no :1`
* List the vnc server
  - `vncserver -list`
* Stop the vnc server
  - `vncserver -kill <:no>`
  - e.g. `vncserver -kill :1`
* Problems:
  - If unable to login desktop, refer to [here](https://devanswers.co/how-to-fix-authentication-is-required-to-create-a-color-profile-managed-device-on-ubuntu-20-04-20-10/).

### x11vnc

* Install x11vnc
  - `sudo apt install x11vnc`
* Set password
  - `x11vnc -storepasswd`
* Run VNC server
  - `x11vnc -forever -usepw -display :0`

## Client

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
