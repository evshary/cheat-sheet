# introduction
cmake is a tool to generate Makefile for multiple platform.

Modern cmake use target and property instead of just variables.

target can be created by 3 commands: add_library, add_executable, add_custom_target.
Almost everything in cmake has properties. Here is [properties list](https://cmake.org/cmake/help/latest/manual/cmake-properties.7.html).

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
* CMAKE_CURRENT_LIST_LINE: Current line of the variable.
* CMAKE_C_FLAGS: Used by C compiler.
* CMAKE_CXX_FLAGS: Used by C++ compiler.
* [LIBRARY_OUTPUT_PATH](https://cmake.org/cmake/help/latest/variable/LIBRARY_OUTPUT_PATH.html): Output library path. (Old varaibles)
* [EXECUTABLE_OUTPUT_PATH](https://cmake.org/cmake/help/v3.7/variable/EXECUTABLE_OUTPUT_PATH.html): Output executable path. (Old variables)

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

# Resource
* [official document](https://cmake.org/cmake/help/latest/index.html)
* [Reserved word for cmake](https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html)
* [eBook](https://github.com/Akagi201/learning-cmake/tree/master/docs)
* [Github: learning-cmake](https://github.com/Akagi201/learning-cmake)
* [Modern CMake 简介](https://zhuanlan.zhihu.com/p/76975231)
