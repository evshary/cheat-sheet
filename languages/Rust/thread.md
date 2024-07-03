# thread

* Basic usage

```rust
use std::thread;

let thread_join_handle = thread::spawn(move || {
    // Do something
});
// Wait for thread to exit
let res = thread_join_handle.join();
```

## Share variables (Need Arc)

### Use Mutex

```rust
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Duration;

fn main() {
    let data = Arc::new(Mutex::new(vec![1, 2, 3]));

    for i in 0..3 {
        let data = data.clone();
        thread::spawn(move || {
            let mut data = data.lock().unwrap();
            data[i] += 1;
        });
    }

    thread::sleep(Duration::from_millis(50));
}
```

### Atomic

* You can also use Atomic
  * Can only use in simple type: bool, u8, u16...
  * Refer to [here](https://doc.rust-lang.org/std/sync/atomic/index.html#structs)

```rust
use std::sync::Arc;
use std::thread;
use std::time::Duration;
use std::sync::atomic::{AtomicU32, Ordering};

fn main() {
    let data = Arc::new(AtomicU32::new(0));

    for _ in 0..3 {
        let data = data.clone();
        thread::spawn(move || {
            let origin_data = data.load(Ordering::Relaxed);
            data.store(origin_data+1, Ordering::Relaxed);
            // Simpler way
            //data.fetch_add(1, Ordering::Relaxed)
        });
    }

    thread::sleep(Duration::from_millis(50));
    println!("{}", data.load(Ordering::Relaxed));
}
```

* For more information about atomic memory order, refer to
  * https://medium.com/fcamels-notes/%E7%B0%A1%E4%BB%8B-c-11-memory-model-b3f4ed81fea6
  * http://senlinzhan.github.io/2017/12/04/cpp-memory-order/
  * Type: https://doc.rust-lang.org/std/sync/atomic/enum.Ordering.html#variants

## Communication

* We can use channel to send message to others

```rust
use std::sync::{Arc, Mutex};
use std::thread;
use std::sync::mpsc;

fn main() {
    let data = Arc::new(Mutex::new(0));

    let (tx, rx) = mpsc::channel();
    for _ in 0..10 {
        let (data, tx) = (data.clone(), tx.clone());

        thread::spawn(move || {
            let mut data = data.lock().unwrap();
            *data += 1;

            tx.send(()).unwrap();
        });
    }

    for _ in 0..10 {
        rx.recv().unwrap();
    }
}
```
