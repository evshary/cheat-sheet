# Programming

Useful commands for programming.

# diff & patch

* Compare the code between two folders
  - `-N`: View the non-exist folder as empty files
  - `-a`: View files as text
  - `-u`: Output 3 same lines
  - `-r`: Recursive folder
```bash
diff -Naur orig_folder new_folder > your.patch
```
* Patch the files: Apply to orig_folder
  - Note: Check old path in the patch file match your path 
```bash
# Test the running result
patch --dry-run -i your.patch
# Patch the files (Will only refer to filename and ignore the path)
patch -i your.patch
# Refer to the path in patch file
patch -p0 -i your.patch
# Ignore the some directory of old path in the patch file
patch -p1 -i your.patch # Ignore 1 directory
patch -p2 -i your.patch # Ignore 2 directories
```
* Patch multiple files
```bash
cat *.patch | patch
```

# Build

* Check what `make install` will do.
  - `make -n install`

# checkinstall

* Refer to [the tutorial](https://www.ptt.cc/bbs/Linux/M.1497723043.A.002.html).
* Install checkinstall
  - `sudo apt install checkinstall`
* interactive command
  - `sudo checkinstall`
* Assign name and version
  - `sudo checkinstall --pkgname=your-pkg-name --pkgversion=your-pkg-version`
