# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name
project(ModuleUselib)

# find library
message("Try to find funclib from ${CMAKE_CURRENT_LIST_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(funclib)
# Add path for include
include_directories(${funclib_INCLUDE_DIRS})

# Assign all the source code in current directory to SOURCES
aux_source_directory(. SOURCES)

# build executable test from source code
add_executable(test_exe ${SOURCES})

# Link with func library
target_link_libraries(test_exe ${funclib_LIBRARIES})

# Set the output of exe to bin folder
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
