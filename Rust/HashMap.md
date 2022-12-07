# HashMap

Need to add `use std::collections::HashMap;` before using.

* Basic Usage

```rust
use std::collections::HashMap

let mut myhash = HashMap::new();
myhash.insert("Key1", 1);

// Replace the original value
let old = myhash.insert("Key1", 2);
assert_eq!(old, Some(1));

// Get the updated value
let new = myhash.get("Key1");
assert_eq!(new, Some(&2))

// Check whether the value exists. Insert while not exists
let v = myhash.entry("Key2").or_insert(3);
assert_eq!(*v, 3);

// Since it exists, will not update the value
let v = myhash.entry("Key2").or_insert(4);
assert_eq!(*v, 3);

// Remove value
// myhash.remove(&key);
myhash.remove("Key1");
```

* Check key exists or not

```rust
if hash.contains_key(&key) {
    // do something
}
```

* Transform from Vec to HashMap

```rust
use std::collections::HashMap;

let list = vec![
    ("Key1", 1),
    ("Key2", 2),
    ("Key3", 3),
];
let hash: HashMap<_,_> = list.into_iter().collect();
println!("{:?}", hash);
```

* Iterate HashMap

```rust
use std::collections::HashMap;

let mut hash = HashMap::new();
hash.insert("key", 1);
for (key, value) in &hash {
    println!("{} {}", key, value);
}
```

* Count the occurrence

```rust
use std::collections::HashMap;

let text = "This is test example."

let mut occur = HashMap::new();
for word in text.split_whitespace() {
    let count = occur.entry(word).or_insert(0);
    *count += 1;  // Update counter in occur
}
println!("{:?}", occur);
```
