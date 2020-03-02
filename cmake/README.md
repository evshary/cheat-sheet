# introduction
cmake is a tool to generate Makefile for multiple platform.

# Installation
* cmake:
  - `sudo apt install cmake`
* ccmake:
  - `sudo apt install cmake-curses-gui`

# Example
* [simple example](simple_example): The simplest one. 
* [multiple folder](multiple_folder): cmake with multiple folder.
* [test and install example](test_install_example): The example for test and install.
* [compile_option_example](compile_option_example): The example for adding compile options.
* [library](library): The example for how to build cmake library.

# Environment Variables List
* CMAKE_SOURCE_DIR: The entry point of CMake.
* CMAKE_BINARY_DIR: The build folder of CMake.
* CMAKE_CURRENT_SOURCE_DIR: The path of current processing CMakeLists.txt.
* CMAKE_CURRENT_BINARY_DIR: The build directory path of current processing CMakeLists.txt.
* CMAKE_CURRENT_LIST_DIR: Current processing path, including `include`. Refer to [Difference between CMAKE_CURRENT_SOURCE_DIR and CMAKE_CURRENT_LIST_DIR](https://stackoverflow.com/questions/15662497/difference-between-cmake-current-source-dir-and-cmake-current-list-dir).

# Useful command
* Debug Build:
```
cmake <location> -DCMAKE_BUILD_TYPE=Debug
```
* Release Build
```
cmake <location> -DCMAKE_BUILD_TYPE=Release
```
* Make
```
# Equals to make
cmake --build <location>
# Equals to make install
cmake --build <location> --target install
```

# Document
We can refer to the [official document](https://cmake.org/cmake/help/latest/index.html) for detail.

The reserved word for cmake is [here](https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html).
