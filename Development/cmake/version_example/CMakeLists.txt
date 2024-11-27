# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name, version
project(test_version VERSION 1.2.3)

# Change config.h.in to config.h
configure_file(config.h.in config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(your_project main.c)
