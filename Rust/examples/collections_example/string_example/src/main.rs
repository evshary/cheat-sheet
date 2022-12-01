fn main() {
    // create string
    let mut s1 = String::new();
    let mut s2 = "My content".to_string();
    let mut s3 = String::from("My content");
    // Update string
    s1.push_str("My content1");
    s2.push_str("2"); // push str
    s3.push('3');     // push char
    // Print
    println!("s1={}", s1);
    println!("s2={}", s2);
    println!("s3={}", s3);
    // Concatenate string
    let s1 = String::from("Hello");
    let s2 = String::from("World");
    let s3 = format!("{} {}", s1, s2);  // Better way to concat
    println!("s3={}", s3);
    let s3 = s1 + " " + &s2;  // Another way, but s1 can't be used again
    println!("s3={}", s3);
    // Iterate String
    let s = String::from("abc");
    for c in s.chars() {   // Output character (based on unicode)
        println!("{}", c);
    }
    for b in s.bytes() {   // Output bytes
        println!("{}", b);
    }
}
