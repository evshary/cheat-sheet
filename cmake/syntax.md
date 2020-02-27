# Useful syntax

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

## if-else statement

```
if(XXX_CONDITION)
elseif(YYY_CONDITION)
else()
endif()
```

## useful operator

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

## string: operation of string

refer to [string](https://cmake.org/cmake/help/latest/command/string.html)

```
# OUTPUT_VAR will be set as "This-is-input"
string(REPLACE " " "-" OUTPUT_VAR "This is input")
# OUTPUT_VAR will be set as "THIS IS INPUT"
string(TOUPPER "this is input" OUTPUT_VAR)
```

## get_property / set_property

refer to [get_property](https://cmake.org/cmake/help/latest/command/get_property.html) & [set_property](https://cmake.org/cmake/help/latest/command/set_property.html)

```
# set property(CACHE entry PROPERTY name value)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
```
