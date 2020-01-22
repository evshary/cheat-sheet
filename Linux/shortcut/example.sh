#!/bin/bash
gnome-terminal -t "Terminal example 1" -e top &
gnome-terminal -t "Terminal example 2" &
# If you want to source rc file before doing something
#gnome-terminal -t "Terminal with source file" -e 'bash -c "source ~/.rc_file; ls"'
# However, note that you should not source .bashrc directly, since there is interaction detection in bashrc.
# If it's not interactive terminal, it doesn't allow you to source bashrc.
exit 0
