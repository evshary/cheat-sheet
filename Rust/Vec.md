# Vec

* Init

```rust
// Init vector
let mut v = Vec::new();
// Init with value
let mut v = vec![4, 5, 6];
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
// Iterate with value
for n in v {
    println!("{}", n);
}
```

# VecDeque

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
