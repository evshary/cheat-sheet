# Go library example

The example show you how to build go library.

* Create new project

```bash
mkdir library_example
go mod init library_example
```

* Write Library
  - In our example, `myfunc.go`

* Build the shared library

```bash
go build -o libmyfunc.so -buildmode=c-shared .
```

* Check whether build is successful or not

```bash
# Should be shared library
file libmyfunc.so
# Should show something
nm -D libmyfunc.so | grep "T myfunc_FirstCall"
```

* Use python to call

```py
import ctypes
lib = ctypes.CDLL("./libmyfunc.so")
lib.myfunc_FirstCall()
```

# Reference
* https://www.darkcoding.net/software/building-shared-libraries-in-go-part-1/
