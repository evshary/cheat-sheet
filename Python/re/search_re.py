import sys
import re

fp = open(sys.argv[1], "r")
try:
    lines = fp.readlines()
    for line in lines:
        match = re.search(r'.* (\d*,\d*) Mb\/s \(', line)
        if match:
            print(match.group(1))
finally:
    fp.close()
