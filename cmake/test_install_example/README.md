# Build
```sh
# Enter build
cd build
# Generate Makefile
cmake ..
# Build code
make
# Show more detail while make
make VERBOSE=1
# Exit build
cd ..
```

# test
```sh
make test
```

# install
* Default install
```sh
make install
```
* To install with your own path, you should add option while calling cmake
```sh
cmake -DCMAKE_INSTALL_PREFIX="/tmp" ..
```
* Or you can add option while calling `make install`
```sh
make install DESTDIR="tmp"
```

# Clean
```sh
# Just remove the files under build folder
rm -rf build/*
```
