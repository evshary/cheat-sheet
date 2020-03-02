# Introduction
This example shows how to use `find_package` to include library.

## Module and Config mode

There are two modes for `find_packages`:

- Module mode: First priority. Use Find<package>.cmake file located within project.
- Config mode: Second priority. Use <package>Config.cmake file located outside and produced by `install`

You can refer to the [Stackoverflow answer](https://stackoverflow.com/questions/20746936/what-use-is-find-package-if-you-need-to-specify-cmake-module-path-anyway).

## Create library

While creating library with cmake, we should use `install(EXPORT...)` for client easy to use.

If you want to support `find_packages`, `configure_package_config_file` and `write_basic_package_version_file` are necessary. Refer to [CMakePackageConfigHelpers](https://cmake.org/cmake/help/latest/module/CMakePackageConfigHelpers.html).

Here are some good references: [cmake install find package](https://murphypei.github.io/blog/2018/11/cmake-install-find-package) and [Learning CMake](https://zhuanlan.zhihu.com/p/87738686) (Both written in Chinese).

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
