# Linux Desktop System

![](https://www.cv.nrao.edu/~pmurphy/Talks/gnome/gnome-fig1.png)
[image source](https://www.cv.nrao.edu/~pmurphy/Talks/gnome/allparts.shtml)
![](https://i.stack.imgur.com/MAB7Y.png)
[image source](https://qastack.cn/unix/345344/difference-between-xorg-and-gnome-kde-xfce)

* X server: Handling input / output, e.g. show display, receive events from mouse/keyboard...
* X client: Receive events from client and decide what to do, e.g. what will happen while the mouse move.
* The protocol between X server and X client called X or X11
* Window manager: Manage multiple X clients, e.g. resize, minimize...
* Device manger: Provide login interface.
  - In Gnome, GNOME Display Manger(gdm) is used.

![](https://www.cv.nrao.edu/~pmurphy/Talks/gnome/gnome-fig2.png)
[image source](https://www.cv.nrao.edu/~pmurphy/Talks/gnome/allparts.shtml)

* Desktop environment: Provide the whole user experience, e.g. panels, menu, starter, icons...
  - Example: GNOME, KDE...
  - Comparison: https://www.eet-china.com/mp/a10976.html

## Reference
* [鳥哥私房菜-第二十三章、X Window 設定介紹](http://linux.vbird.org/linux_basic/0590xwindow.php)
* [What is the difference between a desktop environment and a window manager?](https://askubuntu.com/questions/18078/what-is-the-difference-between-a-desktop-environment-and-a-window-manager)

# Settings

* Use another desktop environment
  - Install xubuntu: `sudo apt install xubuntu-desktop`
  - Remove xubuntu: `sudo apt purge xubuntu-* xfce4-* plymouth-theme-xubuntu-*`
  - (Optional) change logo: `sudo update-alternatives --config default.plymouth`
* `/etc/X11/default-display-manager`: Show what display manager is running. Default is `/usr/sbin/gdm3`.
  - If you want to change display manger, please use `sudo dpkg-reconfigure gdm`
* `/etc/gdm3/custom.conf`: GDM settings, i.e. whether to login automatically(AutomaticLoginEnable/AutomaticLogin).

# Environment Variables

* `XDG_CURRENT_DESKTOP`: what the desktop environment is, e.g. ubuntu:GNOME
* `XDG_SESSION_TYPE`: what kind of protocol used currently, e.g. x11.
* `DISPLAY`: X display name.

# Useful tools

## xrandr

Used for monitor settings.

Refer to https://clay-atlas.com/blog/2020/10/23/linux-cn-xrandr-adjust-resolution-screen-settings/

* Get information: `xrandr`
* Show screen:
```bash
# Show both screen
xrandr --output eDP-1 --auto --output HDMI-1 --auto
# Turn off one screen
xrandr --output eDP-1 --auto --output HDMI-1 --off
```
* Set screen sync / extension
```bash
# HDMI in right
xrandr --output eDP-1 --left-of HDMI-1
# HDMI in left
xrandr --output eDP-1 --right-of HDMI-1
# Set sync
xrandr --output eDP-1 --same-as HDMI-1
```
* Set resolution
```bash
xrandr --output eDP-1 --mode 1920x1080
```

## xhost

Manage who can access X server

```bash
# Show the current allowed list
xhost
# Allow all access
xhost +
# Add local user
xhost +local:username
# Add remote user
xhost +inet:username@domain.name
```
