#!/usr/bin/python3

import subprocess

# The output will show in stdout
## Only one command
process_runner = subprocess.run("ls")
## To get the return code
print("The `ls` return code is %d" % process_runner.returncode)


## Command with argments
process_runner = subprocess.run("ls -al", shell=True)
## To get the return code
print("The `ls -al` return code is %d" % process_runner.returncode)
