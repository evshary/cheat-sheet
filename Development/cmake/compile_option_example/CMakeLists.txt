# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name
# This will init the following variables
# PROJECT_NAME: project name
# PROJECT_SOURCE_DIR, <PROJECT-NAME>_SOURCE_DIR: The path of the CMakeLists.txt
# PROJECT_BINARY_DIR, <PROJECT-NAME>_BINARY_DIR: In the example, build
project(test_project)

# Message
message("This is a CMake example.")

# Process the folder src
add_subdirectory(src)
