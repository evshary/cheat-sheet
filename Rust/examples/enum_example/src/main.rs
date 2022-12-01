#[derive(Debug)]
enum UsState {
    Alabama,
    // ignore...
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

/* enum with match */
fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) => {
            println!("State of quarter from {:?}", state);
            25
        }
    }
}

fn simple_enum() {
    let mycoin = Coin::Penny;
    println!("mycoin is {}", value_in_cents(mycoin));
    let mycoin = Coin::Nickel;
    println!("mycoin is {}", value_in_cents(mycoin));
    let mycoin = Coin::Dime;
    println!("mycoin is {}", value_in_cents(mycoin));
    let mycoin = Coin::Quarter(UsState::Alabama);
    println!("mycoin is {}", value_in_cents(mycoin));
}

enum Event {
    Load,
    KeyPress(char,char),
    Paste(String),
    Click { x: i64, y: i64 },
}

fn show_event(event: Event) {
    match event {
        Event::Load => println!("Page Load"),
        Event::KeyPress(c1,c2) => println!("Pressed {} {}", c1, c2),
        Event::Paste(s) => println!("Paste {}", s),
        Event::Click {x,y} => println!("Click x={}, y={}", x, y),
    }
}

fn enum_with_struct() {
    let load    = Event::Load;
    let pressed = Event::KeyPress('x','y');
    let pasted  = Event::Paste(String::from("my text"));
    let click   = Event::Click { x: 20, y: 80 };

    show_event(load);
    show_event(pressed);
    show_event(pasted);
    show_event(click);
}

enum Toy {
    Doll,
    Robot,
    Car,
}

fn if_let_example() {
    for toy in [Toy::Doll, Toy::Robot, Toy::Car] {
        // Others
        match toy {
            Toy::Doll => println!("Girl"),
            _ => println!("Boy"),
        }
        // Another way for others
        if let Toy::Doll = toy {
            println!("Girl");
        } else {
            println!("Boy");
        }
    }
}

fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

fn option_example() {
    let five = Some(5);
    let six = plus_one(five);
    let none = plus_one(None);
    println!("five is {}", five.unwrap());
    println!("six is {}", six.unwrap());
    if none.is_some() == false {
        println!("none is empty");
    }
}

fn main() {
    println!("** Simple enum example");
    simple_enum();
    println!("** Enum example with struct");
    enum_with_struct();
    println!("** if let example");
    if_let_example();
    println!("** option example");
    option_example();
}
