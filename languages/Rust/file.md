# file

How to read files with Rust

There are [4 ways to read files](https://kerkour.com/rust-read-file)

# Read as bytes

The example from [here](https://doc.rust-lang.org/std/macro.include_bytes.html)

```rust
let bytes = include_bytes!("myfile.txt");
assert_eq!(bytes, b"Hello World\n");
```
