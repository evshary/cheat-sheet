fn main() {
    /* Vector */
    // init
    let mut v1: Vec<i32> = Vec::new();
    let v2 = vec![1, 2, 3];
    // Add value
    v1.push(1);
    v1.push(2);
    // Get value
    match v1.get(2) {
        Some(third) => println!("Third value of v1 is {}", third),
        None => println!("Third value of v1 does not exist"),
    }
    let third: &i32 = &v2[2];  // if index does not exist, throw exception
    println!("Third value of v2 is {}", third);
    // Iterate
    for i in &mut v1 {
        *i += 50;
        println!("{}", i);
    }
    for i in &v2 {
        println!("{}", i);
    }
}
