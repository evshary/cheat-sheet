# Simple Go project example

The example show you how to start a go project.

* Create new project
  - Will create `go.mod` to record used packages

```bash
mkdir <project-name>
go mod init <project-name>
```

* Add packages (Optional)
  - Update the package list in `go.mod`
  - Will create `go.sum` to record the actual version of the package you use

```bash
go get -d <package path>
# go get -d golang.org/x/example/hello
# -d means only download not installed, and will be default in the future
```

* Write your own code
  - In our example, `example.go`

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
