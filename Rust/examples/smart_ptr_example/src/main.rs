use std::ops::Deref;
use std::ops::DerefMut;
use std::rc::Rc;

struct MyBox<T>(T);

impl<T> MyBox<T> {
    fn new(x: T) -> MyBox<T> {
        MyBox(x)
    }
}

impl<T> Deref for MyBox<T> {
    type Target = T;
    fn deref(&self) -> &T {
        &self.0
    }
}

impl<T> DerefMut for MyBox<T> {
    fn deref_mut(&mut self) -> &mut T {
        &mut self.0
    }
}

impl<T> Drop for MyBox<T> {
    fn drop(&mut self) {
        println!("Drop MyBox");
    }
}

fn main() {
    // 1. Box smart pointer
    {
        let x = 5;
        let y = Box::new(x);
        println!("{}", x+*y);
    }
    // 2. Create your own deref
    {
        let mut x = MyBox::new(5);
        *x += 2;
        println!("{}", *x);
    }
    // 3. Rc smart pointer
    {
        let a = String::from("Hello World");
        let b = Rc::new(a);
        println!("{}", Rc::strong_count(&b));
        let c = b.clone();
        println!("{}", Rc::strong_count(&b));
    }
}
