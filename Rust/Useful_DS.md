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
// Push value
v.push(value);
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
