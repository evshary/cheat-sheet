// The generic template type supports trais: PartialOrd and Copy
// You can also use "fn largest<T: PartialOrd + Copy>(list: &[T]) -> T {"
fn largest<T>(list: &[T]) -> T
    where T: PartialOrd + Copy,
{
    let mut largest = list[0];
    for &item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

use std::fmt::Display;
struct Pair<T> {
    x: T,
    y: T,
}
impl<T> Pair<T> {
    fn new(x: T, y: T) -> Self {
        Self {x, y}
    }
}
impl<T: Display + PartialOrd> Pair<T> {
    fn cmp_display(&self) {
        if self.x >= self.y {
            println!("The max: x = {}", self.x);
        } else {
            println!("The max: y = {}", self.y);
        }
    }
}

// Define lifecycle 'a
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

fn main() {
    // 1. Generic Type to get largest number
    let number_list = vec![34, 50, 25, 100, 65];
    let result = largest(&number_list);
    println!("Max number is {}", result);
    let char_list = vec!['y', 'm', 'a', 'q'];
    let result = largest(&char_list);
    println!("Max char is {}", result);

    // 2. Generic Type for struct
    let p1 = Pair {x: 5, y: 10};
    let p2 = Pair::new(10, 5);
    p1.cmp_display();
    p2.cmp_display();

    // 3. Lifecycle to get reference
    let string1 = String::from("Long long string");
    {
        let string2 = String::from("string");
        let result = longest(string1.as_str(), string2.as_str());
        println!("Longest string is {}", result);
    }

    // 4. static lifecycle
    let _s: &'static str = "Never die until the program ends";
}