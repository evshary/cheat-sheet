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

### Version

rustup can manage the Rust toolchain version you want to use.

There are 3 release channels

* stable: released in every 6 weeks
* beta: The next release stable (update every 6 weeks)
* nightly: Update every night

```bash
# Show the current version we are using
rustup show
# List all the downloaded toolchains
rustup toolchain list
# Set the default toolchain version
rustup default stable
rustup default 1.85.0
# Install a specific toolchain version
rustup toolchain install nightly
rustup toolchain install 1.85.0
```

The priority of the version:

* Specify the version in the CLI
  * `cargo +nightly clippy`
  * `cargo +1.85.0 clippy`
* Use the version in `rust-toolchain.toml`
* Use the default version in rustup

The full version is `<channle/version>-<target tripple>`

For example: `stable-x86_64-unknown-linux-gnu` or `1.75.0-x86_64-pc-windows-msvc`

### Platform

rustup support cross platform compilation.

Here is the [platform support list](https://doc.rust-lang.org/nightly/rustc/platform-support.html)

* Add the target

```bash
rustup target add x86_64-pc-windows-msvc
rustup target add aarch64-unknown-linux-gnu
```

* Run commands with the taget

```bash
cargo build --target=x86_64-pc-windows-msvc
cargo build --target=aarch64-unknown-linux-gnu
```

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
