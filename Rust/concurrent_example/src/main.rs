use std::sync::{mpsc, Arc, Mutex};
use std::thread;
use std::time::Duration;

fn main() {
    // 1. Channel to pass information
    let (tx, rx) = mpsc::channel();
    let tx1 = tx.clone();
    let handle1 = thread::spawn(move || {
        let vals = vec![
            String::from("a1"),
            String::from("a2"),
            String::from("a3"),
        ];
        for v in vals {
            tx.send(v).unwrap();
            thread::sleep(Duration::from_secs(1));
        }
    });
    let handle2 = thread::spawn(move || {
        let vals = vec![
            String::from("b1"),
            String::from("b2"),
            String::from("b3"),
        ];
        for v in vals {
            tx1.send(v).unwrap();
            thread::sleep(Duration::from_secs(1));
        }
    });
    for received in rx {
        println!("Receive: {}", received);
    }
    handle1.join().unwrap();
    handle2.join().unwrap();
    // 2. Mutex
    let counter = Arc::new(Mutex::new(0));
    let mut handles = vec![];
    for _ in 0..10 {
        let counter = Arc::clone(&counter);
        let handle = thread::spawn(move || {
            let mut num = counter.lock().unwrap();
            *num += 1;
        });
        handles.push(handle);
    }
    for handle in handles {
        handle.join().unwrap();
    }
    println!("Result is {}", *counter.lock().unwrap());
}
