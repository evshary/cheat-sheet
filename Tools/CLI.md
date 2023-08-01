# Development
## Editor
* vim: No need to explain.
* hd: Show hex file.
* bvi: Hex file editor.

## Version
* git: Version control tool.
* tig: Better git log viewer.

## Shell
* zsh: Better shell.
* tmux: Shell session manager.
* byobu: Friendly shell session manager based on tmux.
* mosh: Keep the network connection for SSH.

## Serial
* minicom: A serial console tool for command line.
* gtkterm: A GUI serial console tool for Linux Desktop.

## debug
* stress: emulate the stress condition on the host.

## Others
* ipython: Better shell for python.
* silversearcher-ag: Used to find the string efficiently.
* cloc: Calculating the line of program.
* ctags: Used to find symbol of C/C++.
* astyle: Adjust the coding style.

# Virtual Machine
* qemu: HW emulator.
* docker: OS virtualization tool.

# System
* neofetch: Used to show the system info.
* lynis: Used to check the security of system
  - Usage: `lynis -c`
* smartmontools: Read the status of disk.
* GParted: Disk Manager in Linux
* mtr: Show the network status. The combination of ping and traceroute.
* tree: List the directory.
* htop, iotop, iftop, powertop
* dstat: vmstat+iostat+ifstat
  - Usage: `alias dstat='dstat -cdlmnpsy'`
* httpie: Useful HTTP client.
  - Usage: `http [URL]`
* ncdu: Enhanced du.
* qdirstat: Same as ncdu, but with GUI.
* tldr: Simplified man.
* trash-cli: Trash in command line.
  - Usage: `trash-list`, `trash-rm`, `trash-put`, `trash-empty`, `restore-trash`
* fd: Simplified find.

# Hacker
* nmap: Host scanner.
* hydra: Tools for password brute force.
* [openssl](https://github.com/evshary/cheat-sheet/blob/master/OpenSSL/README.md): Encryption tool.
* sqlmap: SQL injection tools.

# Community
* [gnupg](https://evshary.github.io/2018/10/14/GnuPG教學/): Used to manage GPG key.
* irssi: Used to connect IRC.

# Health
* Text fonts (Ubuntu)
  - Univeral Access => Large Text
* Displays => Night Light
* DCMTK: Transform DICOM to png
  - Installation: `sudo apt install dcmtk`
  - Transform: `dcm2pnm --write-png image.dcm output.png`

# Others
* qpdf: PDF transformer
  - Decrypt the pdf: `qpdf --password=password --decrypt origin.pdf unsecured.pdf`
* [gnuplot](https://evshary.github.io/2018/12/02/gnuplot：報告必備的繪圖工具/): Able generate graph.
* [youtube-dl](https://evshary.github.io/2018/11/25/youtube-dl網路影片下載器/): Youtube downloader.
  - [yt-dlp](https://github.com/yt-dlp/yt-dlp): youtube-dl 的 fork，但速度更快
* [ffmepg](https://evshary.github.io/2018/12/01/ffmpeg影音處理工具/): Multimedia convertor.
* mocp: CLI music player
  - `sudo apt install moc moc-ffmpeg-plugin`
  - `mocp`: Run the music player
* [Live Captions](https://opensource.com/article/23/2/live-captions-linux)

```shell
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
flatpak install flathub net.sapples.LiveCaptions
# Run
flatpak run net.sapples.LiveCaptions
```
