# Object Oriented

Rust does not too many object-oriented features, but there are some tips to make it more similar to the object-oriented language.

## Private member

```rust
mod lib {
    pub struct Car;
    impl Car {
        pub fn run(&self) { // public method
            self.drive();   // Call private method
        }
    }
    impl Car {
        fn drive(&self) { // private method
            println!("Driving");
        }
    }
}

fn main() {
    let car = lib::Car{};
    car.run();
}
```

## Getters and Setters

```rust
pub struct Robot {
    battery: i32
}
impl Robot {
    pub fn new() -> Robot {
        Robot {battery: 50}
    }
    fn set_battery(&mut self, battery: i32) {
        self.battery = battery;
    }
    pub fn get_battery(&self) -> i32 {
        self.battery
    }
    pub fn charge(&mut self) {
        self.set_battery(100);
    }
}
fn main() {
    let mut r = Robot::new();
    println!("Battery: {}", r.get_battery());
    r.charge();
    println!("Battery: {}", r.get_battery());
}
```

## Polymorphism

```rust
pub trait Drive {
    fn drive(&self);
}

pub struct Toyota;
impl Drive for Toyota {
    fn drive(&self) {
        println!("Driving a Toyota car");
    }
}

pub struct Honda;
impl Drive for Honda {
    fn drive(&self) {
        println!("Driving a Honda car");
    }
}

fn main() {
    let mut cars = Vec::new() as Vec<Box<Drive>>;
    cars.push(Box::new(Toyota));
    cars.push(Box::new(Honda));
    for c in &cars {
        c.drive();
    }
}
```

## Reference

* [[Rust] 程式設計教學：物件導向 (Object-Oriented Programming)](https://opensourcedoc.com/rust-programming/oop/)
