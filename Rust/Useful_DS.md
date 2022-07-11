# Vec

* Init

```rs
// Init vector
let mut v = Vec::new();
// Init with value
let mut v = vec![4, 5, 6];
```

* Update

```rs
// Push value
v.push(value);
// Sort from small to big
v.sort();
// Sort from big to small
v.sort_by(|a, b| b.cmp(a));
```

* Iterate

```rs
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

```rs
// Create HashMap
let mut hash = HashMap::new();
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
