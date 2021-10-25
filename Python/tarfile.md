# Compress & Uncompress

To compress & uncompress, need to `import tarfile` first.

# Compress

```py
import tarfile
import os
with tarfile.open("myfolder.tar.gz", "w:gz") as tar:
    tar.add("myfolder", arcname=os.path.basename("myfolder"))
```

# Uncompress

```py
import tarfile
with tarfile.open("myfolder.tar.gz", "r:gz") as tar:
    tar.extractall(".")
```

