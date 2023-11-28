#!/usr/bin/python3

import os

# The output will be stdout
# return value will be return code
my_retcode = os.system("ls -al")

print("My return code is %d" % my_retcode)
