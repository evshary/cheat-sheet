# Lifetime

Lifetime is used while you are using reference.
This can make sure the reference will be valid while operation.

There are 3 conditions to eliminate the lifetime

1. Every input arguments(reference) have their own lifetime.
2. If there is only one input argument(reference), then the return value(reference) will be the same lifetime.
3. While there are many input arguments(reference) and one of them is `&self` or `&mut self`, then the output value(reference) will be the same as `&self`.

# Syntax

```rust
&i32        // reference
&'a i32     // reference with explicit lifetime
&'a mut i32 // mutable reference with explicit lifetime
```

# Function

```rust
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}
```

# Structure

Refer to http://web.mit.edu/rust-lang_v1.25/arch/amd64_ubuntu1404/share/doc/rust/html/book/second-edition/ch19-02-advanced-lifetimes.html

```rust
// str should live longer than Context
struct Contect<'a> (&'a str);

// Context should live longer than Parser
// 's lifetime >= 'c lifetime
struct Parser<'c, 's: 'c> {
    context: &'c Context<'s>,
}
// If you want their lifetime are the same
struct Parser<'a> {
    context: &'a Context<'a>,
}

// implementation
// impl<'a> means <'a> is lifetime
// Parser<'a> means this is its implementation
impl<'a> Parser<'a> {
    fn parse<'a>(&'a self) -> Result<(), &'a str> {}
    // Can be abbreviated
    fn parse(&self) -> Result<(), &str> {}
}
```

# Self-referential type problem

```rust
struct Foo<'a> {
    x: i32,
    y: Option<&'a i32>,
}

impl<'a> Foo<'a> {
    fn new() -> Self {
        Foo {
            x: 4,
            y: None,
        }
    }
    // Since you don't use reference, no need to define lifetime
    fn init_x(&mut self) {
        self.x = 5;
    }
    // You use reference, so need to define lifetime
    fn init_y<'b: 'a>(&'b mut self) {
        self.y = Some(&self.x);
    }
    // You can abbreviate the lifetime
    // Note that you don't need init_y_new<'a>, because <'a> is already defined
    fn init_y_new(&'a mut self) {
        self.y = Some(&self.x);
    }
}
fn main() {
    let mut f = Foo::new();
    f.init_x();
    f.init_y();
}
```

The reason why we need to define `'a` in `fn init_y_new(&'a mut self)`:

1. Origin function should be `fn init_y_new<'b>(&'b mut self)`
2. We use `self.y` in the function and the lifetime of `self.y` should be larger than `'a`
3. Should be `fn init_y_new<'b: 'a>(&'b mut self)`
4. Lifetime can be the same: `fn init_y_new(&'a mut self)`

# Reference

* [生命周期与引用有效性](https://rustwiki.org/zh-CN/book/ch10-03-lifetime-syntax.html#%E7%94%9F%E5%91%BD%E5%91%A8%E6%9C%9F%E7%9C%81%E7%95%A5lifetime-elision)
