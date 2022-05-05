use std::thread;
use std::time::Duration;

fn generate_workout(intensity: u32, random_num: u32) {
    let expensive_closure = |num| {
        println!("Slow computing");
        thread::sleep(Duration::from_secs(1));
        num
    };
    if intensity < 25 {
        println!("Do exercise 1 {} times", expensive_closure(intensity));
        println!("Do exercise 2 {} times", expensive_closure(intensity));
    } else {
        if random_num == 3 {
            println!("Drink water");
        } else {
            println!("Run {} minutes", expensive_closure(intensity));
        }
    }
}

fn main() {
    generate_workout(10, 7);

    let v1: Vec<i32> = vec![1, 2, 3];
    let v2: Vec<_> = v1.iter().map(|x| x + 1).collect();
    for v in v2 {
        println!("{}", v);
    }
}
