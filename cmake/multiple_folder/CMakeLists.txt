# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name
project(test_project)

# Assign all the source code in current directory to SOURCES
aux_source_directory(. SOURCES)

# Add subdirectory func
add_subdirectory(func)

# build executable test from source code
add_executable(test_exe ${SOURCES}) 

# Link with func library
target_link_libraries(test_exe func_lib)