# Print type

```rust
fn main() {
    let blank1 = [1;3];
    print_type_of(&blank1);
}

fn print_type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>());
}
```
