# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name
project(test_project)

# Assign all the source code in current directory to SOURCES
aux_source_directory(. SOURCES)

# build executable test from source code
add_executable(test_exe ${SOURCES}) 

# Setting CMAKE_INSTALL_PREFIX
# Default is /usr/local, but we can assign it while calling cmake or make
# set(CMAKE_INSTALL_PREFIX /tmp)

# install to {CMAKE_INSTALL_PREFIX}/bin
install(TARGETS test_exe DESTINATION bin)

# Good way to install header: https://stackoverflow.com/questions/10487256/cmake-how-to-properly-copy-static-librarys-header-file-into-usr-include
# set_target_properties(mylib PROPERTIES PUBLIC_HEADER "myheader1.h;myheader2.h")
# install(TARGETS mylib 
#         LIBRARY DESTINATION some/libpath
#         PUBLIC_HEADER DESTINATION some/includepath
# )

# Enable testing
enable_testing()

# Normal test case
# add_test(test_run_abcdef test_exe abcdef)
# set_tests_properties(test_run_abcdef PROPERTIES PASS_REGULAR_EXPRESSION "abcdef")

# Writing test case as macro
macro(run_test_case arg1 result)
  add_test(test_${arg1} test_exe ${arg1})
  set_tests_properties(test_${arg1} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(run_test_case)

# This test case should be correct
run_test_case(123 "123")
# This test case should be error
run_test_case(abc "123")
