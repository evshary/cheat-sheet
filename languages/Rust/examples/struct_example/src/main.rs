// To enable debug
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

// impl contains "Associated Functions"
impl Rectangle {
    // constructor
    fn square(size: u32) -> Rectangle {
        Rectangle {
            width: size,
            height: size,
        }
    }
    // method
    fn area(&self) -> u32 {
        self.width * self.height
    }
    // method with parameters
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

fn main() {
    let rect1 = Rectangle {
        width: dbg!(3*10), // able to debug here
        height: 50,
    };
    let rect2 = Rectangle::square(10);

    // Note that we are not using {} here (Need to enable debug)
    println!("rect1 is {:?}", rect1);  // print all members
    println!("rect2 is {:#?}", rect2); // print all members with better format
    dbg!(&rect1);  // Using RUST builtin debug

    // Call methods
    println!("Area of rect1: {}", rect1.area());
    println!("Area of rect2: {}", rect2.area());
    if rect1.can_hold(&rect2) {
        println!("rec1 can contain rect2.");
    }
}
