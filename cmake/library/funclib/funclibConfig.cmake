# IMPORTED means the library is outside the project
add_library(funclib STATIC IMPORTED)

# Get the library path
find_library(FUNC_LIBRARY_PATH funclib HINTS "${CMAKE_CURRENT_LIST_DIR}/../../")
set_target_properties(funclib PROPERTIES IMPORTED_LOCATION "${FUNC_LIBRARY_PATH}")

# Include files
find_path(FUNC_INCLUDE_PATH func.h HINTS "${CMAKE_CURRENT_LIST_DIR}/../../../include")
message("${CMAKE_CURRENT_LIST_DIR}/../../../include")
include_directories(${FUNC_INCLUDE_PATH})
