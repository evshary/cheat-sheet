# Introduction

There are 3 ways to create packages:

* dpkg-buildpackage
  - Do the following things
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

# Steps

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
* Use dpkg-buildpackage
  - `dpkg-buildpackage -rfakeroot -b -uc -us`
* Use debuild
  - Build: `debuild -b -uc -us`
  - Clean: `debuild -- clean`

# Reference
* [[Debian套件打包] 設定好debian目錄後的打包](http://wen00072.github.io/blog/2014/06/12/package-debian-packages-set-after-list-of-debian-packages/): Several ways to generate deb files
* [Building debian packages with debuild](https://blog.packagecloud.io/debian/debuild/packaging/2015/06/08/buildling-deb-packages-with-debuild/): How to generate simple packages
* [How To Build Debian Packages From Source](https://ostechnix.com/how-to-build-debian-packages-from-source/)