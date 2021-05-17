# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name, version
project(RMT_agent VERSION 0.9.0)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)
add_executable(thread.out thread.c)
target_link_libraries(thread.out PRIVATE Threads::Threads)

# Another way to use pthread in cmake
#add_executable(thread.out thread.c)
#target_link_libraries(thread.out PRIVATE pthread)

add_executable(fork.out fork.c)
