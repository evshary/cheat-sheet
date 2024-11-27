# minimum cmake version
cmake_minimum_required(VERSION 3.10)

# project name, version
project(funclib VERSION 1.2.3)

# Assign all the source code in current directory to LIB_SOURCES
aux_source_directory(. LIB_SOURCES)

# Generate library
add_library(funclib ${LIB_SOURCES})

# We add prefix to install directory
# This is just for convenience
set(CMAKE_INSTALL_PREFIX install)

# Add include directory
target_include_directories(funclib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}> # headers for building
    $<INSTALL_INTERFACE:include>           # headers for install
  )

# We need to include CMakePackageConfigHelpers before using
# configure_package_config_file or write_basic_package_version_file
include(CMakePackageConfigHelpers)
# Create <Package>Config.cmake from PackageConfig.cmake.in
configure_package_config_file(
    "cmake/PackageConfig.cmake.in"
    "${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION lib/cmake  # I think this line is not necessary, but cmake still needs it...
  )
# Create <Package>Version.cmake
write_basic_package_version_file(
    "${PROJECT_NAME}Version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
  )

# For make install
install(FILES func.h DESTINATION include)
# <Package>Config.cmake and <Package>Version.cmake should be also installed
install(FILES
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Version.cmake"
    DESTINATION lib/cmake
  )
# Add EXPORT for funclib
install(TARGETS funclib EXPORT funclib DESTINATION lib)
# Able to install export
install(EXPORT funclib
    NAMESPACE ${PROJECT_NAME}:: # Add namespace
    FILE "${PROJECT_NAME}Targets.cmake"
    DESTINATION lib/cmake
  )
