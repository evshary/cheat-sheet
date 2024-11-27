# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name
project(test_project)

# Assign all the source code in current directory to SOURCES
aux_source_directory(. SOURCES)

# build executable test from source code
# The below code equals to
# add_executable(test_exe func.c test.c)
add_executable(test_exe ${SOURCES})
