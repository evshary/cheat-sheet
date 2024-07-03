# Introduction

Rust is the language designed for performance, safe, and safe concurrency.

There are 3 binaries for rust.

* rustup: Manage Rust installation
* rustc: Rust compiler
* cargo: Package Manager

## Install

* Install rustup
  * the binary of rust will be in `~/.cargo/bin`, and rustup will setup the environemt variable for you.
  * The environment settings `. "$HOME/.cargo/env"` will be under `~/.profile`, `~/.bashrc` and `~/.zshenv`.

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

## Usage

### rustc

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

### cargo

* Create new project
  * It'll create Cargo.toml and src folder
  * `Cargo.toml` will record the package you need and `Cargo.toml` will record the specific version of dependencies related to the package.

```sh
cargo new hello_world
# If you want to create library
# cargo new --lib hello_world
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

### Platform

We can add `--target=xxx` to compile with on different platform.

* ARM64: `--target=aarch64-unknown-linux-gnu`
* ARM32: `--target=arm-unknown-linux-gnueabi`

More platform can refer to [here](https://doc.rust-lang.org/nightly/rustc/platform-support.html)

## Important Concept

* Ownership:
  * Scalar type and tuple with scalar type can assign with clone
  * Others is assigned with move
  * You can use "reference" without copy
* Generic Type
* Trait
* Lifecycle
* Smart Pointers
* Async

## Reference

* [The Rust Programming Language](https://doc.rust-lang.org/book/)
  * [中文版](https://rust-lang.tw/book-tw/)
* [Rust语言圣经(Rust Course)](https://course.rs/about-book.html)
* [RUST 練習題](https://zh.practice.rs/why-exercise.html)
* [通过例子学 Rust](https://rustwiki.org/zh-CN/rust-by-example/index.html)
* [Rust学习笔记](https://skyao.io/learning-rust/)
* [RUST playground](https://play.rust-lang.org/)
* [Rust to Assembly Code](https://rust.godbolt.org/)
