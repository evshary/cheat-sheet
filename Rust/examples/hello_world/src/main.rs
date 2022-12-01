use std::io;
use std::cmp::Ordering;
// from rand
use rand::Rng;

fn main() {
    println!("Hello, world! This is Guessing Game:");

    let secret_number = rand::thread_rng().gen_range(1..101);

    loop {
        println!("Please enter your input:");
        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read_line");
        /* We shadow the guess here */
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        println!("Your guess is {}", guess);

        // Compare with secret_number
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small"),
            Ordering::Equal => {
                println!("Matched");
                break;
            },
            Ordering::Greater => println!("Too large"),
        }
    }
}
