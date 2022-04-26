/* MODULE A */
mod module_a {
    pub mod module_a1 {    // make mod public
        pub fn func() {  // make func public
            println!("module A");
        }
    }
    pub struct StructA {
        pub public_u32: u32,
        private_u32: u32,
    }
    impl StructA {
        pub fn get_private_u32(&self) -> u32 {
            self.private_u32
        }
        pub fn constructor(num1: u32, num2: u32) -> StructA {
            StructA {
                public_u32: num1,
                private_u32: num2,
            }
        }
    }
}

/* MODULE B */
mod module_b {
    pub mod module_b1 {
        pub fn func() {
            println!("module B");
        }
    }
}
// use with absolute path
use crate::module_b::module_b1;
// use with relative path
//use self::module_b::module_b1;

/* MODULE C */
pub mod module_c;

pub fn myfunc() {
    // Absolute Path (Starts with crate)
    crate::module_a::module_a1::func();
    // Relative Path
    module_a::module_a1::func();
    // Access struct
    let mystruct = crate::module_a::StructA::constructor(200, 100);
    println!("public u32 of mystruct: {}", mystruct.public_u32);
    println!("private u32 of mystruct: {}", mystruct.get_private_u32());

    // Utilize "use"
    module_b1::func();

    // Call module_c
    module_c::module_c1::func();
}