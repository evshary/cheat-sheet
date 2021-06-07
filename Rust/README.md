# Introduction

Rust is the language designed for performance, safe, and safe concurrency.

There are 3 binaries for rust.

* rustup: Manage Rust installation
* rustc: Rust compiler
* cargo: Package Manager

# Install

* Install rustup
  - the binary of rust will be in `~/.cargo/bin`, and rustup will setup the environemt variable for you.

```sh
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
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
# Build: create target folder
cargo build
# Release build
cargo build --release
```

* Run the project

```sh
cargo run
```
