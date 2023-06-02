# flatpak

flatpak is the packages manager which can cross different Linux distributions

# Install

```shell
# Ubuntu
sudo apt install flatpak
# Add flathub (System)
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
# Add flathub (User, only needed if you want users can install packages by themselves)
flatpak remote-add --user --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
```

# Usage

```shell
# Search available APP
flatpak search [APP name]

# Install APP
flatpak install [APP name]

# Run APP
flatpak run [APP name]

# Update APP
flatpak update	更新應用程式

# Uninstall APP
flatpak uninstall [APP name]
# Uninstall APP with user data
flatpak uninstall [APP name] --delete-data

# List installed APP
flatpak list

# List remotes
flatpak remotes
```

# Reference
* [Linux系統如何安裝Flatpak軟體套件？使用教學](https://ivonblog.com/posts/linux-flatpak-introduction/)
