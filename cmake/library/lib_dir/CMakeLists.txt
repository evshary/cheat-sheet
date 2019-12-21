# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name
project(somelib)

# Assign all the source code in current directory to LIB_SOURCES
aux_source_directory(. LIB_SOURCES)

# Generate library
add_library(func_lib ${LIB_SOURCES})

# Set the output of library to lib folder
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) 
