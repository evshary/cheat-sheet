use std::collections::HashMap;

fn main() {
    // Insert key-value
    let mut scores = HashMap::new();
    scores.insert(String::from("teamA"), 10);
    scores.insert(String::from("teamB"), 50);
    println!("{:?}", scores);
    // Get value
    let team_name = String::from("teamC");
    let score = scores.get(&team_name); // This will return Option
    if score == None {
        println!("{} not exist", team_name);
    }
    // Update value
    scores.insert(String::from("teamA"), 30);
    scores.entry(String::from("teamA")).or_insert(50);  // if teamA exists, don't update
    scores.entry(String::from("teamC")).or_insert(60);  // if teamC not exists, insert 60
    // Iterate hash table
    for (key, value) in &scores {
        println!("{}: {}", key, value);
    }
    // Update based on old value
    let score = scores.entry(String::from("teamA")).or_insert(0);
    *score += 1;
    println!("{:?}", scores);
    // Use mapping
    let teams = vec![String::from("teamA"), String::from("teamB")];
    let init_score = vec![10, 50];
    let scores: HashMap<_, _> = teams.into_iter().zip(init_score.into_iter()).collect();
    println!("{:?}", scores);
}
