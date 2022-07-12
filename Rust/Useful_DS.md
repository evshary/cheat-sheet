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

# LinkedList

* You should add `use std::collections::LinkedList;` first.

* Init

```rust
let mut list1 = LinkedList::new();
let mut list2 = LinkedList::from([1, 2, 3]);
```

* Update

```rust
// Push to the back
list1.push_back(5);
// Push to the front
list1.push_front(4);
// Pop the last item
*list.pop_back().unwrap();
// Pop the first item
*list.pop_front().unwrap();
```

* Useful methods

```rust
// Length of LinkedList
list.len();
// Get the last item
*list1.back().unwrap();
// Get the first item
*list1.front().unwrap();
```

* Iterate

```rust
// Not mutable
let mut iter = list.iter();
assert_eq!(iter.next(), Some(&0));
assert_eq!(iter.next(), Some(&1));
assert_eq!(iter.next(), Some(&2));
assert_eq!(iter.next(), None);
// Mutable
for element in list1.iter_mut() {
    *element += 10;
}
```

# HashMap

* You should add `use std::collections::HashMap;` first.

* Init

```rust
// Create HashMap
let mut hash = HashMap::new();
// Init with key/value
let mut hash = HashMap::from([
    ("key1", "value1"),
    ("key2", "value2"),
    ("key3", "value3"),
]);
```

* Useful Method

```rust
// If key exists (Use reference)
if hash.contains_key(&key) {
    // do something
}
// Add key
hash.insert(key, value);
```

# Algorithm

* Compare

```rust
use std::cmp;
min_val = cmp::min(val1, val2);
min_val = cmp::max(val1, val2);
```

* Swap

```rust
use std::mem;

let mut x = 5;
let mut y = 42;

mem::swap(&mut x, &mut y);
```

# String

* Init

```rust
// String
let str1: String = String::new();
let str2: String = String::from("New String");
// str
let str3: &str = "New str";
// transform
// String => str
let str4: &str = String::from("New String").as_str();
// str => String
let str5: String = "New str".to_string();
// String/str => bytes array
let mybytes: &[u8] = str1.as_bytes();
// String/str => Vec<u8>
let myvec: Vec<u8> = str1.as_bytes().to_vec();
```

* Useful Method

```rust
// Append string
str1.push_str("Append Data");
// Get length
str1.len();
```

* Get index

```rust
// Get index of string
// print 4th bytes
println!("{}", str1.as_bytes()[4]);
// print 4th char
println!("{}", str1.as_bytes()[4] as char);
println!("{}", str1.chars().nth(4).unwrap());
// iterate string
for b in str1.as_bytes() {
    println!("{}", b); // print bytes
}
for c in str1.chars() {
    println!("{}", c); // print char
}
```

* Slice

```rust
let mystr = "This is str";
let myslice = &mystr[0..4];
```

* Concatenation

```rust
// String with str
let hello = String::new("Hello ");
let world = "World"
let helloworld = hello + world;
// String with String
let hello = String::new("Hello ");
let world = String::new("World");
let helloworld = hello + &world;
```
