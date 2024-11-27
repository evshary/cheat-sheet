# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name
project(ConfigUselib)

# find library
find_package(funclib REQUIRED CONFIG PATHS "${CMAKE_SOURCE_DIR}/../funclib/build/install/lib/cmake/")

# Assign all the source code in current directory to SOURCES
aux_source_directory(. SOURCES)

# build executable test from source code
add_executable(test_exe ${SOURCES})

# Link with func library
target_link_libraries(test_exe funclib::funclib)

# Set the output of exe to bin folder
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
