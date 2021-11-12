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

# Reference
* [鳥哥私房菜-第二十三章、X Window 設定介紹](http://linux.vbird.org/linux_basic/0590xwindow.php)
* [What is the difference between a desktop environment and a window manager?](https://askubuntu.com/questions/18078/what-is-the-difference-between-a-desktop-environment-and-a-window-manager)
