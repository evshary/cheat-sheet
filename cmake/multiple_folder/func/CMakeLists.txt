# Assign all the source code in current directory to LIB_SOURCES
aux_source_directory(. LIB_SOURCES)

# Generate library
add_library(func_lib ${LIB_SOURCES})