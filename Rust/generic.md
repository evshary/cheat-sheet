# generic

# turblefish

We can use turblefish to tell Rust which type we want.

```rust
let v: Vec<i32> = Vec::new();
// or
let v = Vec::<i32>::new();
```

If you want to use something like `collect::<Vec<i32>>()`,
you need to define `fn collect<B>(self) -> B `.

Refer to [here](https://techblog.tonsser.com/posts/what-is-rusts-turbofish)
