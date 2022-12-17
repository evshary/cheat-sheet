# iterator

# iter() / iter_mut() / into_iter()

* `iter()`: iterates over the items by reference
* `iter_mut()`: iterates over the items, giving a mutable reference to each item
* `into_iter()`: iterates over the items, moving them into the new scope

Refer to [here](https://stackoverflow.com/questions/34733811/what-is-the-difference-between-iter-and-into-iter)

# Operate on every element

* map & collect: Operate on iterator and generate array
* for_each: do operation on all elements

```rust
let v = [1,2,3];
// collect need to know the final type
// Both two ways are ok
let new_v: Vec<i32> = v.iter().map(|x| x * 2).collect();
//let new_v = v.iter().map(|x| x * 2).collect::<Vec<i32>>();
new_v.iter().for_each(|x| println!("{}", x));
```

