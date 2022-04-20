# Basic Knowledge

## variables & const

```rust
// immutable
let x = 4;
// mutable
let mut x = 4;
// const
const x: u32 = 10 * 10;
```

## Data Types

* Scalar Types: integers, floating-point, booleans, characters
* Compound Types: tuples, arrays

```rust
// integers: i8,u8,i16,u16,i32,u32,i64,u64,i128,u128,isize,usize
//           isize&usize depends on architecture
//           content: 1_000_000, 0xff, 0o77, 0b1111_0000, b'a'(u8 only)
let x: u8 = 0xff;
// floating-points: f32,f64
let x: f32 = 4.32;
// boolean: bool
let x: bool = true;
// character: 4 bytes in size
let x = 'a';
// tuples
let tup: (i32, f32, i8) = (500, 6.4, 1);
let (x, y, z) = tup;
let x = tup.0;
let y = tup.1;
let z = tup.2;
// array
let arr: [i32:5] = [3, 3, 3, 3, 3];
let arr = [3; 5];
```

# function

Note that return value should not include ';'

```rust
fn plus_one(x: i32) -> i32 {
    x + 1
}
```

# control flow

* if Expressions

```rust
// if Expressions
let x = 5;
if x == 5 {
    println!("5");
} else if x == 6 {
    println!("6");
} else {
    println!("no!!!");
}
// if with let statement
let condition = true;
let num = if condition { 5 } else { 6 };
```

* loop Expressions

```rust
// Able to break outside loop
let mut rows = 0;
'count_row: loop {
    let mut cols = 0;
    loop {
        if cols == 3 {
            break;
        }
        println!("rows:{} cols:{}", rows, cols);
        if rows == 2 && cols == 2 {
            break 'count_row;  // We can break out of count_row directly
        }
        cols += 1;
    }
    rows += 1;
}
// Use loop to assign value
let mut count = 0;
let result = loop {
    count += 1;
    if count == 2 {
        break count * count;
    }
};
println!("result={}", result);
```

* while Expressions

```rust
let mut count = 3;
while count != 0 {
    println!("count={}", count);
    count -= 1;
}
```

* for Expressions

```rust
// Iterate array
let arr = [10, 20, 30, 40];
for element in arr {
    println!("element={}", element);
}
// Iterate range (reverse)
for num in (1..5).rev() {  // means from 1 to 4
    println!("num={}", num);
}
```

# Ownership

* Scalar type and tuple with scalar type can assign with clone
  - They are stored in **stack**

```rust
let x = 5;
y = x;
println!("x={}, y={}", x, y);
let x = (5, 'a');
y = x;
println!("x=({},{}), y=({},{})", x.0, x.1, y.0, y.1);
```

* Others will be assigned with move
  - They are stored in **heap**

```rust
let s1 = String::from("string1");
// invalid
let s2 = s1;
println!("s1={}, s2={}", s1, s2);
// valid
let s2 = s1.clone();
println!("s1={}, s2={}", s1, s2);
```

* Function will take the ownership of heap

```rust
fn take_ownership(s: String, i: u32) {
    println!("take_ownership");
}
fn take_and_give_back(s: String) -> String {
    println!("take_and_give_back");
    s
}
fn main() {
    let s = String::from("hello");
    let i = 5;
    take_ownership(s, i);
    // invalid
    println!("s={}", s);
    // valid
    println!("i={}", i);
    let s = String::from("hello");
    let s = take_and_give_back(s);
    println!("s={}", s);
}
```

## Reference

* Use reference instead of copy

```rust
fn getlen(s: &String) -> usize {
    s.len()
}
fn main() {
    let s = String::from("hello");
    let len = getlen(&s);
    println!("The len of {} is {}", s, len);
}
```

* Able to modify reference

```rust
fn change(s: &mut String) {
    s.push_str(" world");
}
fn main() {
    let mut s = String::from("hello");
    change(&mut s);
    println!("s={}", s);
}
```

* Unable to use multiple mut reference to the same value

```rust
let mut s = String::from("hello");
// valid: You can have several not-mut reference
let r1 = &s;
let r2 = &s;
println!("r1={}, r2={}", r1, r2); 
// invalid: You can't have several not-mut reference
let r1 = &mut s;
let r2 = &mut s;
println!("r1={}, r2={}", r1, r2); 
// invalid: Even one mut and one not-mut reference
let r1 = &s;
let r2 = &mut s;
println!("r1={}, r2={}", r1, r2); 
```

* reference should always be available

```rust
fn dangle() -> &String {
    let s = String::from("hello");
    // Since s will be invalid after exiting the function, we can't use that reference.
    &s  // invalid
}
fn main() {
    let r = dangle();
}
```

* string slice

```rust
// str means string slice
fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    &s[..]
}
fn main() {
    let mystring = String::from("hello world");
    let word = first_word(&mystring);
    println!("word={}", word);
}
```
