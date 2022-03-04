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
* [compile option example](compile_option_example): The example for adding compile options.
* [version example](version_example): The example for how to add version in cmake project.
* [package](package): The example for how to package your project to deb fil.
* [library](library): The example for how to build cmake library.
* [include external project](https://zhuanlan.zhihu.com/p/102050750):
  - There are 3 ways to include external project: submodule(add_subdirectory), ExternalProject_Add, FetchContent
  - For the first way, to avoid install not necessary binary: add_subdirectory(external_project EXCLUDE_FROM_ALL). Refer to [this](https://stackoverflow.com/questions/35344132/cpack-exclude-install-commands-from-subdirectory-googletest-directory).

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
* PROJECT_SOURCE_DIR: The source directory of this cmake project (Note that it'll point to the source folder of subproject.) 
* PROJECT_BINARY_DIR: The build directory of this cmake project (Note that it'll point to the build folder of subproject.)
* CMAKE_PROJECT_VERSION: The version for cmake project.

# Useful command
* Debug Build:
```bash
cmake <location> -DCMAKE_BUILD_TYPE=Debug
```
* Release Build
```bash
cmake <location> -DCMAKE_BUILD_TYPE=Release
```
* Make
```bash
# Equals to make
cmake --build <location>
# Equals to make install
cmake --build <location> --target install
```
* See the detail of cmake
```bash
cmake --debug-output <location>
# More detail
cmake --trace <location>
```
* Set verbose to see the detail of make
```bash
# Add verbose while make
make VERBOSE=1
# Or add definition before make
cmake <location> -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
```
* Decide the build folder and install folder (`./build` and `./install`)
```bash
cmake -Bbuild -H. -DCMAKE_INSTALL_PREFIX=./install
```
* If your cmake is library and you want to link to it, export the environmental variables.
```bash
export LD_LIBRARY_PATH=$PWD/install/lib/
```

# Resource
* [official document](https://cmake.org/cmake/help/latest/index.html)
* [Reserved word for cmake](https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html)
* [eBook](https://github.com/Akagi201/learning-cmake/tree/master/docs)
* [Github: learning-cmake](https://github.com/Akagi201/learning-cmake)
* [Modern CMake 简介](https://zhuanlan.zhihu.com/p/76975231)
* [CMake 如何入门？](https://www.zhihu.com/question/58949190)
