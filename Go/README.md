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

# Go project

* Create new project
  - Will create go.mod to record used packages

```bash
mkdir <project-name>
go mod init <project-name>
```

* Build / Run / Clean project

```bash
go build .
go run .
go clean
```

* Remove unused packages

```bash
go mod tidy
```

# Reference
