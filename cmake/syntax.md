# Useful syntax

## debug

```
# The debug message will be shown while running cmake
message("======== This is debug message ${CMAKE_BINARY_DIR} ========")
```

## project

refer to [project](https://cmake.org/cmake/help/latest/command/project.html)

```
project(CY_NAME VERSION 1.0.0)
# We can use the following variable
# PROJECT_VERSION, CY_NAME_VERSION
# PROJECT_VERSION_MAJOR, CY_NAME_VERSION_MAJOR
# PROJECT_VERSION_MINOR, CY_NAME_VERSION_MINOR
# PROJECT_VERSION_PATCH, CY_NAME_VERSION_PATCH
```

## option 

```
# option(OPT_NAME "Statement" default_value)
option(FLAG "This is statement" ON)
# We can use ${WERROR} to get value
```

## configure_file

```
# Replace ${VAR} or @VAR@ in input file, and output
configure_file(<input> <output>)
# Replace only @VAR@ in input file, and output
configure_file(<input> <output> @ONLY)
# Only copy
configure_file(<input> <output> COPYONLY)
```

## if-else statement

```
if(XXX_CONDITION)
elseif(YYY_CONDITION)
else()
endif()
```

## useful operator

* Fackage found:
```
find_package (Python COMPONENTS Interpreter Development QUIET)
if (Python_FOUND)
endif()
if (NOT Python_FOUND)
endif()
```
* Logical operation:
```
if(NOT expr)
if(expr1 AND expr2)
if(expr1 OR expr2)
```
* Compare operation:
```
if(var LESS num)
if(var GREATER num)
if(var EQUAL num)
```
* String compare operation:
```
if(str1 STREQUAL str2)
```
* Regular expression operation:
```
if(variable MATCHES regex)
```
* File operation:
```
if(EXISTS filename)
if(file1 IS_NEWER_THAN file2)
if(IS_ABSOLUTE path)
```
* Others
```
if(DEFINED var)
```

## function

refer to [function](https://cmake.org/cmake/help/latest/command/function.html)

```
function(callfunc i j)
  message(${i})
  message(${j})
endfunction()

# Now we can use callfunc(1 2)
```

* Some useful variable
  - `${ARGN}`: The actual argument - argument needed by function
  - `${ARGC}`: The number of argument

## foreach

refer to [foreach](https://cmake.org/cmake/help/latest/command/foreach.html)

```
# Output 0 1 2 3 4 5
foreach(i RANGE 0 5)
  message(${i})
endforeach()
# Use list
set(LIST 1 2 3)
foreach(i LIST)
  message(${i})
endforeach()
```

## string: string operation

refer to [string](https://cmake.org/cmake/help/latest/command/string.html)

```
# OUTPUT_VAR will be set as "This-is-input"
string(REPLACE " " "-" OUTPUT_VAR "This is input")
# OUTPUT_VAR will be set as "THIS IS INPUT"
string(TOUPPER "this is input" OUTPUT_VAR)
```

## file: file operation

refer to [file](https://cmake.org/cmake/help/latest/command/file.html)

```
# globbing-expression: find all files which match "test.h" and put into FILES_VAR
file(GLOB FILES_VAR test.h)
# Create file: create <file_name> with <content>
file(WRITE <file_name> <content>)
```

## list: list operation

refer to [list](https://cmake.org/cmake/help/latest/command/list.html)

```
# Append element into list
list(APPEND <list> [<element>...])
```

## get_property / set_property

refer to [get_property](https://cmake.org/cmake/help/latest/command/get_property.html) & [set_property](https://cmake.org/cmake/help/latest/command/set_property.html)

```
# set property(CACHE entry PROPERTY name value)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
```
