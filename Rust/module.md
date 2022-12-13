# Module

* `use`: Used to abbreviate the path
* `mod`:
  1. Separate namespace
  2. Include other files

```rust
// Separate namespace
mod a {
    pub mod a1 {
        pub fn a2() {}
    }
}
mod b {
    pub fn test() {
        // absolute
        crate::a::a1::a2();
        // relative
        super::a::a1::a2();
    }
}
// crate tree:
// crate <-- this is root
//  ├─a
//  │ └a1
//  │   └a2
//  └─b
//    └test
```

```rust
// include other files
// file.rs
pub mod module {
    pub fn func1() {}
}
// lib.rs
mod file;  // only need in lib.rs / main.rs to create crate tree
pub use crate::file::module;
pub fn test() {
    module::func1();
}
```

# pub

* `pub`: No limitation to visibility
* `pub(crate)`: Only seen in the current crate
* `pub(self)`: Only seen in current mod
* `pub(super)`: Only seen parents' mod
* `pub(in <path>)`: Only seen in certain path mod, i.e. `pub(in crate::a)`

# Dependencies

The library under the `[dependencies]` in Cargo.toml can be used directly, no need mod.

# Reference

* [Clear explanation of Rust’s module system](https://www.sheshbabu.com/posts/rust-module-system/): Really clear about what the Rust's module system
  - Mandarin version: https://skyao.io/learning-rust/docs/build/module/rust-module-system-explanation.html
