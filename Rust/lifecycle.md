# Lifecycle

Lifecyle is used while you are using reference.
This can make sure the reference will be valid while operation.

There are 3 conditions to eliminate the lifecycle

1. Every input arguments(reference) have their own lifecyle.
2. If there is only one input argument(reference), then the return value(reference) will be the same lifecycle.
3. While there are many input arguments(reference) and one of them is `&self` or `&mut self`, then the output value(reference) will be the same as `&self`.

# Syntax

```rust
&i32        // reference
&'a i32     // reference with explicit lifecyle
&'a mut i32 // mutable reference with explicit lifecycle
```

```rust
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}
```

# Reference

* [生命周期与引用有效性](https://rustwiki.org/zh-CN/book/ch10-03-lifetime-syntax.html#%E7%94%9F%E5%91%BD%E5%91%A8%E6%9C%9F%E7%9C%81%E7%95%A5lifetime-elision)
