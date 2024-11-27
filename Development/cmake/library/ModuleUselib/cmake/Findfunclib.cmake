# Set funclib_INCLUDE_DIR as the location of func.h
find_path(funclib_INCLUDE_DIR NAMES "func.h"
          HINTS "${CMAKE_SOURCE_DIR}/../funclib/build/install/include" )
# Set funclib_LIBRARY as the location of libfunclib.a
find_library(funclib_LIBRARY NAMES funclib
          HINTS "${CMAKE_SOURCE_DIR}/../funclib/build/install/lib" )

set(funclib_INCLUDE_DIRS ${funclib_INCLUDE_DIR} )
set(funclib_LIBRARIES ${funclib_LIBRARY} )

# The following will be defined:
#  funclib_FOUND - funclib is found
#  funclib_INCLUDE_DIRS - Include directories for funclib
#  funclib_LIBRARIES - Libraries directories for funclib
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(funclib
    FOUND_VAR funclib_FOUND
  REQUIRED_VARS
    funclib_INCLUDE_DIRS
    funclib_LIBRARIES
)
