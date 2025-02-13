# Vector

## Vec

* Init

```rust
// Init vector
let mut v = Vec::new();
// Init with value
let mut v = vec![4, 5, 6];
```

* Index

```rust
let v = vec![1,2,3,4,5];
let third: &i32 = &v[2];  // Will error in no this index
match v.get(2) {
    Some(third) => println!("{}", third),
    None => println!("Not exist"),
}
```

* Update

```rust
// Push value to the back
v.push(value);
// Pop the value from the back
let value = *v.pop().unwrap();
// Sort from small to big
v.sort();
// Sort from big to small
v.sort_by(|a, b| b.cmp(a));
```

* Useful methods

```rust
// Get size
v.len();
// Empty or not
v.is_empty();
// Get last item
// Note v.last() return Option and v.last().unwrap() return reference
if *v.last().unwrap() == 5 {
    // do something
}
// Get last mutable item
// The same as last()
if *v.last_mut().unwrap() == 5 {
    // do something
}
// Swap two elements
v.swap(idx1, idx2);
```

* Iterate

```rust
// Iterate with index
for i in 0..v.len() {
    println!("idx:{}, value:{}", i, v[i]);
}
for (i,val) in v.iter().enumerate() {
    println!("idx:{}, value:{}", i, val);
} 
// Iterate with value (unable to reuse)
for n in v {
    println!("{}", n);
}
for n in v.into_iter() {
    println!("{}", n);
}
// Iterate for reuse later
for n in &v {
    println!("{}", n);
}
for n in v.iter() {
    println!("{}", n);
}
// Iterate for mutable borrow
for n in &mut v {
    println!("{}", n);
}
for n in v.iter_mut() {
    println!("{}", n);
}
// Reverse
for n in v.iter().rev() {
    println!("{}", n);
}
```

* Pass vector to function

```rust
fn take_ownership(v1: &mut Vec<i32>){
    v1.push(42);
}

fn main() {
    let mut v1 = vec![1, 2, 3];
    take_ownership(&mut v1);
    println!("{:?}", v1);
}
```

## VecDeque

* You should use `use std::collections::VecDeque;` first.

* Init

```rust
// Init VecDeque
let mut v = VecDeque::new();
// Init with value
let mut v = VecDeque::from([4, 5, 6]);
```

* Update

```rust
// Push to back 
v.push_back(2);
// Push to front
v.push_front(1);
// Pop from back
*v.pop_back().unwrap();
// Pop from front
*v.pop_front().unwrap();
```

* Useful methods

```rust
// Get size
v.len();
// Empty or not
v.is_empty();
// Get the first item
if *v.front().unwrap() == 5 {
    // do something
}
// Get the first mutable item
if *v.front_mut().unwrap() == 5 {
    // do something
}
// Get the last item
if *v.back().unwrap() == 5 {
    // do something
}
// Get the last mutable item
if *v.back_mut().unwrap() == 5 {
    // do something
}
```
