# Introduction
This example shows how to use `find_package` to include library.

# Build
* Build library first
```sh
# Enter build
cd lib_dir/build
# Generate Makefile
cmake ..
# Build code
make
# Show more detail while make
make VERBOSE=1
# Exit build
cd ../..
```
* Build the code which uses library
```sh
# Enter build
cd use_lib/build
# Generate Makefile
cmake ..
# Build code
make
# Show more detail while make
make VERBOSE=1
# Exit build
cd ../..
```

# Clean
```sh
# Just remove the build folder
rm -rf lib_dir/build/* use_lib/build/*
```
