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
* Run debuild
  - `debuild -b -uc -us`
* Clean intermediate files
  - `debuild -- clean`

# Reference
* [Building debian packages with debuild](https://blog.packagecloud.io/debian/debuild/packaging/2015/06/08/buildling-deb-packages-with-debuild/)