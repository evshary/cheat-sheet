# The following setting which starts with "CMAKE_" must be set before add_executable
# RPATH settings
## Don't skip RPATH for the build tree
set(CMAKE_SKIP_BUILD_RPATH FALSE)
## Use RPATH while building
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
## Set the RPATH
set(CMAKE_INSTALL_RPATH "/opt")
## Use RPATH while install
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
## You can also set RPATH to certain target
#set_property(
#    TARGET mytarget
#    PROPERTY INSTALL_RPATH
#    "@loader_path/../lib"
#    "@loader_path/../thirdparty/lib"
#)

# Set output folder: Same function as EXECUTABLE_OUTPUT_PATH and LIBRARY_OUTPUT_PATH
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Assign all the source code in current directory to SOURCES
aux_source_directory(. SOURCES)

# --- Source file ---
# build executable test from source code
add_executable(test_exe ${SOURCES})

# We also can add other source code later
# target_sources(test_exe PRIVATE other.cpp)

# --- include file ---
# Add include file
include_directories(${PROJECT_SOURCE_DIR}/include)
# We also can add include file to target
#target_include_directories(test_exe PRIVATE ${PROJECT_SOURCE_DIR}/include)

# --- definition ---
target_compile_definitions(test_exe PRIVATE NEW_VERSION PROJECTS="${PROJECT_NAME}")
# Equal to
#add_definitions(-DNEW_VERSION -DPROJECTS="${PROJECT_NAME}")

# --- compile options ---
target_compile_options(test_exe PRIVATE -std=c++11 -Wall)
# Equal to the following, use CMAKE_C_FLAGS for C
#set(CMAKE_CXX_FLAGS "-std=c++11")
#set(CMAKE_CXX_FLAGS "-Wall")

# --- define debug/release build ---
# For debug build
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
# For release build
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

#  --- link library ---
# Add library search path
#link_directories(${PROJECT_SOURCE_DIR}/lib)
# Link libtest.a
#target_link_libraries(test_exe PRIVATE test)

# --- add dependencies ---
# Make sure other target is build before
#ADD_DEPENDENCIES(test_exe other_target)

# --- Set build tools if needed ---
#set(CMAKE_C_COMPILER "/path/to/your/c/compiler/executable")
#set(CMAKE_CXX_COMPILER "/path/to/your/cpp/compiler/executable")
#set(CMAKE_ASM_COMPILER "/path/to/your/asm/executable")
#set(CMAKE_AR "/path/to/your/ar/executable")

# Set output folder
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#set(LIBRARY_OUTPUT_PATH${PROJECT_BINARY_DIR}/lib)
