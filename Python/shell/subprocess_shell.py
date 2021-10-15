#!/usr/bin/python3

import subprocess

# The output will show in stdout
## Only one command
file_lists = subprocess.run("ls")
## To get the return code
print("The `ls` return code is %d" % file_lists.returncode)


## Command with argments
file_lists = subprocess.run("ls -al", shell=True)
## To get the return code
print("The `ls -al` return code is %d" % file_lists.returncode)
