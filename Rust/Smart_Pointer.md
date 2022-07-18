# Box

* Basic usage

```rust
struct Mystruct {
    a: i32,
    b: u16,
}

// init
let s1 = Box::from(Mystruct { a: 0, b: 1 });
println!("{} {}", s1.a, s1.b);  // 0 1
// modify
let mut s2 = Box::from(Mystruct { a: 1, b: 2 });
s2.a = 100;
s2.b = 1000;
println!("{} {}", s2.a, s2.b);  // 100 1000
```

* Why Box?
  - Data in heap can be transferred without copy
  - Able to used recursive type (Don't know the exact size)

```rust
let arr = [0;1000]; // 0 for 1000 times
let arr1 = arr; // will do the copy
println!("{:?}", arr.len());
println!("{:?}", arr1.len());
let arr = Box::new([0;1000]);
let arr1 = arr; // transfer ownership, and arr will not be used again
//println!("{:?}", arr.len()); // Can't be used again
println!("{:?}", arr1.len());
```

```rust
struct LinkedList {
    val: i32,
    next: Option<Box<LinkedList>>,
}
/*
struct LinkedListBad {
    val: i32,
    next: Option<LinkedListBad>, // unable to count the size of LinkedListBad
}
*/
let list1 = LinkedList { val: 10, next: None};
println!("{}", list1.val);
```

# Rc & Ac

* When you want to use multiple pointers which point to the same data
* Need `use std::rc::Rc;`

```rust
// Wrong
let s = String::from("hello, world");
let a = Box::new(s);
let b = Box::new(s); // s has already been transferred to a
```

```rust
// Correct way
use std::rc::Rc;
let a = Rc::new(String::from("hello, world"));
let b = Rc::clone(&a); // b and a point to the same data
println!("{} {}", Rc::strong_count(&a), Rc::strong_count(&b)); // should be 2 2
```

* Ac is same as Rc, but can be used in multithread.
* Ac need `use std::sync::Arc;`

# RefCell

You can't borrow an unmutable value with mutable way, but RefCell provides us the flexibility.
The checking mechanism will be postponed to runtime

Need `use std::cell::RefCell;`

```rust
// Error while compile
let x = 5;
let y = &mut x;
println!("{} {}", x, y);
// Panic while runtime
let w = RefCell::new(5);
let x = w.borrow();
let y = w.borrow_mut(); // panic at this line
println!("{} {}", x, y);
```

Similar operation

```rust
let cell = RefCell::new(10);
{
    let mut mut_ref = cell.borrow_mut();
    *mut_ref += 1;
}
println!("{}", cell.borrow());
let mut test = 10; // in stack, but you need to define as mut
{
    let test1 = &mut test;
    *test1 += 1;
}
println!("{}", test);
let mut ptr = Box::new(10); // in heap, but you need to define as mut
{
    let ptr2 = ptr.as_mut();
    *ptr2 += 1;
}
println!("{}", ptr);
```

But why we need RefCell, refer to https://www.sobyte.net/post/2022-03/rust-why-need-interior-mutability/
