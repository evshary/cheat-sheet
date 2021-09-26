# Installation

* Download Go from the [official website](https://golang.org/doc/install)
* Remove old binary and uncompress to /usr/local/go

```bash
sudo su
rm -rf /usr/local/go && tar -C /usr/local -xzf go<version>.linux-amd64.tar.gz
```

* Add PATH to `~/.profile`

```bash
export PATH=$PATH:/usr/local/go/bin
```

* Check version by `go version`

# Evironment variable

You can see the environmental variables by `go env`.

* GOROOT: where you install go and how to find standard library, should be `/usr/local/go`
* GOPATH: where the packages you download, should be `~/go`

# Manage the packages

All the downloaded packages will be under `~/go/pkg/mod/`

* Install external package

```bash
go install <package path>
# go install golang.org/x/example/hello@latest
```

* Clean all packages

```bash
go clean -modcache
```

# Example
* [simple_example](simple_example): Simple Go project example.

# Reference
* [Go 语言教程](https://www.runoob.com/go/go-tutorial.html)
