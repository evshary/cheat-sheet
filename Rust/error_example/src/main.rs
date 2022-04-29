use std::fs::File;
use std::io::{self, ErrorKind, Read};

fn read_from_file() -> Result<String, io::Error> {
    // 1. complete
    /*
    let f = File::open("hello.txt");
    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };
    let mut s = String::new();
    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
    */
    // 2. more simpler
    let mut s = String::new();
    File::open("hello.txt")?.read_to_string(&mut s)?;
    Ok(s)
}

fn main() {
    // 1. Panic directly for any errors but with our message
    let _f = File::open("hello.txt").expect("Unable to open the files");
    // 2. Panic directly for any errors
    let _f = File::open("hello.txt").unwrap();
    // 3. most complete way to handle error
    let _f = File::open("hello.txt");
    let _f = match _f {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("Create file fails: {:?}", e),
            },
            other_err => panic!("Open file fails: {:?}", other_err),
        },
    };
    // 4. Simpler way
    let _f = File::open("hello.txt").unwrap_or_else(|error| {
        if error.kind() == ErrorKind::NotFound {
            File::create("hello.txt").unwrap_or_else(|error| {
                panic!("Create file fails: {:?}", error);
            })
        } else {
            panic!("Create file fails: {:?}", error);
        }
    });

    // Read the content from the file
    match read_from_file() {
        Ok(s) => println!("file content is {}", s),
        Err(e) => panic!("Fail to read from file {:?}", e),
    };
}
