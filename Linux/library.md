# Library

There are two kinds of library in Linux: static and dynamic library

# static library

It contains all of the object files in *.a

# dynamic library

It ends with .so, and you can use `ldd` to check where it links to.

# library in library

* link static library A to static library B: This should be OK.
* link static library A to dynamic library B: Not suggest, it'll lose the benefits of dynamic library (position independent)
* link dynamic library A to static library B: Not suggest, you need to make sure the application which use static library is able to link to dynamic library.
* link dynamic library A to dynamic library B: This should be OK. Please refer to [here](https://stackoverflow.com/questions/19424494/linking-a-shared-library-with-another-shared-lib-in-linux)
  * If your application that uses library B doesn't know the path of library A, you need to add **RUNPATH** (replace RPATH) or `LD_LIBRARY_PATH`.
  * Most of the time, `LD_LIBRARY_PATH` is much more useful because we can't assure library B has a correct **RUNPATH** configuration.
  * A better way is to install both library A and library B in the same folder. You can link your application to that path.
