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
