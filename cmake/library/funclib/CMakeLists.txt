# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name
project(funclib)

# Assign all the source code in current directory to LIB_SOURCES
aux_source_directory(. LIB_SOURCES)

# Generate library
add_library(funclib ${LIB_SOURCES})

set(CMAKE_INSTALL_PREFIX .)
install(TARGETS funclib DESTINATION install/lib)
install(FILES func.h DESTINATION install/include)
