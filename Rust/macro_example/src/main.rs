macro_rules! calculate {
    (eval $e:expr) => {
        {
            let result = $e;
            println!("{} = {}", stringify!{$e}, result);
        }
    };
    (eval $e1:expr, $(eval $e2:expr),+) => {
        {
            calculate! { eval $e1 }
            calculate! { $(eval $e2),+ }
        }
    };
}

fn main() {
    calculate!{
        eval 1 + 1,
        eval 2 + 2
    };
}
