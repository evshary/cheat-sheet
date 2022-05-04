pub fn add_two(a: i32) -> i32 {
    a + 2
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_true_case() {
        assert_eq!(4, add_two(2));
    }

    #[test]
    fn test_false_case() {
        assert_ne!(4, add_two(0));
    }

    #[test]
    fn add_two_to_zero() {
        assert_eq!(2, add_two(0));
    }

    #[test]
    fn add_two_to_minus() {
        assert_eq!(0, add_two(-2));
    }
}
