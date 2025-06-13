# Implicit Coversion

## Auto borrowing

User can simplify the method call in a struct.

```rust
struct A;

impl A {
    fn hello(&self) {
        println!("Hello");
    }
}

fn main() {
    let a = A;
    (&a).hello(); // without auto-borrowing
    a.hello();    // with auto-borrowing
}
```

## Auto dereferencing

If we can derefer from C to B to A, we can call the function in A without the explicit dereference.

```rust
use std::ops::Deref;

struct A;
impl A {
    fn hello(&self) {
        println!("Hello from A!");
    }
}

struct B(A);
impl Deref for B {
    type Target = A;
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

struct C(B);
impl Deref for C {
    type Target = B;
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

fn main() {
    let c = C(B(A));
    (**c).hello(); // without auto-dereferencing
    c.hello();     // with auto-dereferencing: Rust finds `hello()` in A via Deref chain: C → B → A
}
```

## Auto coercion

Able to automatically convert between related **reference** types.

```rust
use std::ops::Deref;

struct B {
    value: i32,
}

struct A {
    inner: B,
}

impl Deref for A {
    type Target = B;
    fn deref(&self) -> &B {
        &self.inner
    }
}

fn show_b(b: &B) {
    println!("{}", b.value);
}

fn main() {
    let a = A { inner: B { value: 42 } };

    let ra = &(*a);   // without auto coercion
    let rb: &B = &a;  // with auto coercion

    show_b(&(*a));    // without auto coercion
    show_b(&a);       // with auto coercion (You don't need to transform from B to A first)
}
```

* `&String` can be auto-coerced to `&str`
* `&Vec<T>` can be auto-coerced to `&[T]`
* `&Box<T>` can be auto-coerced to `&T`

```rust
let b: Box<T> = Box::new(...);
let r: &T = &b; // auto-coercion

// This is same if we use the method defined in smart function
let r: &T = b.as_ref();
```
