# Python Implementation

## CPython

* The official implementation.
* Written in C (call glibc)
* Map `PyObject` to `struct`
  1. Wrap your C functions into Python code
  2. Define your own module
  3. Compile it as a shared library
  4. Python now can load it
* Use GIL(Global Interpreter Lock)
  * Removing GIL needs to rewrite the whole code
  * It will use too many Mutex
  * Only affects module thread but not module multiprocessing
* PyO3: Python can call Rust
  * Compile Rust code to a library having the C interface
  * CPython can execute that library

## JPython

* Written in Java (Rely on JVM)

## PyPy

* Written in Python, but with Just-In-Time compiler

## MicroPython

* Used in embedded system
