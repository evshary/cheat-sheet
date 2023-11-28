# Read / Write file

* Read

```py
# 1st way
f = open("myfile.txt", "r")
# Read each line
for line in f:
    print(line)
f.close

# 2nd way
with open("myfile.txt", "r") as f:
    # Read all content
    content = f.read()
```

* Write

```py
# 1st way
f = open("myfile.txt", "w")
f.write("test123")
f.close

# 2nd way
with open("myfile.txt", "w") as f:
    f.write("test123")
```

# Check file / directory

* check whether file / directory exists or not

```py
import os
# File exists or not
os.path.isfile("./myfile")
# Directory exists or not
os.path.isdir("./mydir")
# No matter file / directory
os.path.exists("./mypath")
```

* Use pathlib

```py
from pathlib import Path
mypath = Path("./mypath")
# File exists or not
if mypath.exists():
    print("mypath exists")
if mypath.is_file():
    print("mypath is a file")
if mypath.is_dir():
    print("mypath is a directory")
```

* List file / directory

```py
import os
# List files and directory
all = [f for f in os.listdir(".")]
print(all)
# Only files
onlyfiles = [f for f in os.listdir(".") if os.path.isfile("./"+f)]
print(onlyfiles)
# Only directories
onlydirectories = [f for f in os.listdir(".") if os.path.isdir("./"+f)]
print(onlydirectories)
```

* List all file recursively (including subdirectory)

```py
import os
for path, dirs, files in os.walk("."):
    print("Under path "+path)
    print("  directory: "+ str(dirs))
    print("  files: "+ str(files))
```
