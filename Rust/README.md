# Introduction

Rust is the language designed for performance, safe, and safe concurrency.

There are 3 binaries for rust.

* rustup: Manage Rust installation
* rustc: Rust compiler
* cargo: Package Manager

# Install

* Install rustup
  - the binary of rust will be in `~/.cargo/bin`, and rustup will setup the environemt variable for you.
  - The environment settings `. "$HOME/.cargo/env"` will be under `~/.profile`, `~/.bashrc` and `~/.zshenv`.

```sh
curl --proto '=https' --tlsv1.2 https://sh.rustup.rs -sSf | sh
```

* Update rust

```sh
rustup update
```

* Uninstall

```sh
rustup self uninstall
```

# Usage

## rustc

* Create `main.rs`

```rust
fn main() {
    println!("Hello, world!");
}
```

* Build code

```sh
rustc main.rs
```

## cargo

* Create new project
  - It'll create Cargo.toml and src folder
  - `Cargo.toml` will record the package you need and `Cargo.toml` will record the specific version of dependencies related to the package.

```sh
cargo new hello_world
cd hello_world
```

* Clean and build the project

```sh
# Clean: remove target folder
cargo clean
# Check compile without creating executables
cargo check
# Build: create target folder
cargo build
# Release build
cargo build --release
```

* Run the project

```sh
cargo run
```

# Basic Knowledge

* variables & const

```rust
// immutable
let x = 4;
// mutable
let mut x = 4;
// const
const x: u32 = 10 * 10;
```

* Data Types
  - Scalar Types: integers, floating-point, booleans, characters
  - Compound Types: tuples, arrays

```rust
// integers: i8,u8,i16,u16,i32,u32,i64,u64,i128,u128,isize,usize
//           isize&usize depends on architecture
//           content: 1_000_000, 0xff, 0o77, 0b1111_0000, b'a'(u8 only)
let x: u8 = 0xff;
// floating-points: f32,f64
let x: f32 = 4.32;
// boolean: bool
let x: bool = true;
// character: 4 bytes in size
let x = 'a';
// tuples
let tup: (i32, f32, i8) = (500, 6.4, 1);
let (x, y, z) = tup;
let x = tup.0;
let y = tup.1;
let z = tup.2;
// array
let arr: [i32:5] = [3, 3, 3, 3, 3];
let arr = [3; 5];
```

* function: Note that return value should not include ';'

```rust
fn plus_one(x: i32) -> i32 {
    x + 1
}
```

* control flow
  - if Expressions

```rust
// if Expressions
let x = 5;
if x == 5 {
    println!("5");
} else if x == 6 {
    println!("6");
} else {
    println!("no!!!");
}
// if with let statement
let condition = true;
let num = if condition { 5 } else { 6 };
```
