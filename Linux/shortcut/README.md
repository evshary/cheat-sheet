# introduction

This is an example for shortcut.

# Usage

1. Put example.sh and example.desktop to your own directory.
2. Modify the path in example.desktop.
3. Changet the permission. (Or right click and choose "Allow launching")
```bash
gio set example.desktop metadata::trusted true
chmod a+x example.desktop
```
4. Double click example.desktop.

# Reference
* [Cannot launch .desktop files (opens with Text Editor instead)](https://askubuntu.com/questions/1187934/cannot-launch-desktop-files-opens-with-text-editor-instead)
* [Creating a program shortcut on the desktop entirely from the terminal (CLI)? - Ubuntu 20.04 / GNOME 3](https://askubuntu.com/questions/1314919/creating-a-program-shortcut-on-the-desktop-entirely-from-the-terminal-cli-u)
