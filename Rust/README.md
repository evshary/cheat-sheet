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
  - Create Cargo.toml and src folder

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
