# Introduction

There are 3 ways to create packages:

* dpkg-buildpackage
  - The command will do the following things
    - clean: `debian/rules clean`
    - apply patches: `dpkg-source -b`
    - build: `debian/rules build`
    - install files to fakeroot: `fakeroot debian/rules binary`
    - use gpg to sign *.dsc
    - generate and sign *.changes
* debuild
  - Do what dpkg-buildpackage does but more checking
* pbuilder
  - Use clean environment to create packages

# Create your own packages

## Formal

* Install necessary packages
```bash
sudo apt-get install devscripts build-essential lintian
```
* Write your own program
* Create debian folder and the following files under debian folder:
  - control: Describe the package information
  - changelog: created by `dch -i --create`
  - rules: How to build the package
  - copyright: It can be blank
  - compat: compatibility
* Packages:
  - Use dpkg-buildpackage
      * `dpkg-buildpackage -rfakeroot -b -uc -us`
  -  Use debuild
      * Build: `debuild -b -uc -us`
      * Clean: `debuild -- clean`

## Simple

* Write your own program
* Create `DEBIAN` folder (must be uppercase)
* Create `DEBIAN/control` file and add necessary information
* Leave current folder and run `dpkg -b <your folder>`

# Download existed packages

* Modify `/etc/apt/sources.list` and uncomment the line of deb-src
* Run `sudo apt update`
* Get the packages `sudo apt source <package name>`, e.g. `sudo apt source hello`
* Install dependencies of the packages: `sudo apt build-dep hello`
* Do the modification to the source code
* Rebuild packages
```bash
cd hello-xxx
dpkg-buildpackage -rfakeroot -b -uc -us
# Or another way
debuild -b -uc -us
```

# Decompress the deb

* See the content of deb: `dpkg -c <your deb>`
* See the installed content: `dpkg -x <your deb> <target folder>`
* See the DEBIAN folder: `dpkg -e <your deb> <target folder>`
* Repackage
  - Unpack: `dpkg-deb -R <your deb> <folder>`
  - Pack: `dpkg-deb <folder> <your deb>`

# Reference
* [[Debian套件打包] 設定好debian目錄後的打包](http://wen00072.github.io/blog/2014/06/12/package-debian-packages-set-after-list-of-debian-packages/): Several ways to generate deb files
* [Building debian packages with debuild](https://blog.packagecloud.io/debian/debuild/packaging/2015/06/08/buildling-deb-packages-with-debuild/): How to generate simple packages
* [How To Build Debian Packages From Source](https://ostechnix.com/how-to-build-debian-packages-from-source/)
* [如何製作「deb檔(Debian Package)」](https://samwhelp.github.io/book-ubuntu-basic-skill/book/content/package/how-to-build-package.html)
* [Easily unpack DEB, edit postinst, and repack DEB](https://unix.stackexchange.com/questions/138188/easily-unpack-deb-edit-postinst-and-repack-deb)
