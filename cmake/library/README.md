# Introduction
This example shows how to use `find_package` to include library.

There are two modes for `find_packages`:

- Module mode: First priority. Use Find<package>.cmake file located within project.
- Config mode: Second priority. Use <package>Config.cmake file located outside and produced by `install`

You can refer to the [Stackoverflow answer](https://stackoverflow.com/questions/20746936/what-use-is-find-package-if-you-need-to-specify-cmake-module-path-anyway).

# Build
* Build library first
```sh
# Enter build
cd func_lib/build
# Generate Makefile
cmake ..
# Build code
make
# Show more detail while make
make VERBOSE=1
# Install
make install
# Exit build
cd ../..
```
* Build the code which uses library
```sh
# Enter build (ConfigUselib/ModulUselib)
cd <USELIB>/build
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
