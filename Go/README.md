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

# Go project

* Create new project
  - Will create `go.mod` to record used packages

```bash
mkdir <project-name>
go mod init <project-name>
```

* Add packages
  - Update the package list in `go.mod`
  - Will create `go.sum` to record the actual version of the package you use

```bash
go get -d <package path>
# go get -d golang.org/x/example/hello
# -d means only download not installed, and will be default in the future
```

* Build / Run / Clean project

```bash
go build .
go run .
go clean
```

* Install / Remove build result

```bash
# will install binary to ~/go/bin
go install
# remove install result
go clean -i -x
```

* Remove unused packages in project

```bash
go mod tidy
```

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

# Reference
* [Go 语言教程](https://www.runoob.com/go/go-tutorial.html)
