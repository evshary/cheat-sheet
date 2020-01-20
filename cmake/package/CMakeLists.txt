# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name
project(test_project)

# Assign all the source code in current directory to SOURCES
aux_source_directory(. SOURCES)

# build executable test from source code
add_executable(test_exe ${SOURCES}) 


# What we want to install
#INSTALL(TARGETS myexe mylib mystaticlib
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION libstatic
#       )
install(TARGETS test_exe
        RUNTIME DESTINATION bin
       )

# Here is cpack settings
## Set the package type
set(CPACK_GENERATOR "DEB")
## Set the package version
set(CPACK_PACKAGE_VERSION "1.0.0")
# Set the package name
set(CPACK_PACKAGE_NAME "test_package_name")
# Set the installation location
set(CPACK_SET_DESTDIR true)
set(CPACK_INSTALL_PREFIX "/opt/test_packages/")
# Set where the deb is 
set(CPACK_OUTPUT_FILE_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/build)
# Maintainer
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "ChenYing Kuo")
# Description
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "This is description.")
# Dependency
# set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.3.1-6), libc6 (<< 3)")
# Must have
include(CPack)
