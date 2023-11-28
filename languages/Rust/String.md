# String
 
The difference between String and &str:
* String: store data into heap
* &str: the slice of String

# Usage

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
let str4: &str = &String::from("New String");
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

Note that we can't index String directly,
since String is UTF-8 and we can't ensure every character is 1 byte.

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
let hello = String::from("Hello ");
let world = "World";
let helloworld = hello + world;
// String with String
let hello = String::from("Hello ");
let world = String::from("World");
let helloworld = hello + &world;
```
