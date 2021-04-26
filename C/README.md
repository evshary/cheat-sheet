# Basic knowledge

* [concept.md](concept.md): Basic concept for C language.
* [common.md](common.md): Commonly used API/syntax.
* [header.md](header.md): Commonly used header and detail.

# Used by C++

Since the symbol of C and C++ are different, we need to add the following code in C header.

```c
#ifdef __cplusplus
extern "C" {
#endif

// your header

#ifdef __cplusplus
} /* extern "C" */
#endif
```
