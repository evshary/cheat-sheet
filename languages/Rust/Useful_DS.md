# Useful_DS

## LinkedList

* You should add `use std::collections::LinkedList;` first.

* Init

```rust
let mut list1 = LinkedList::new();
let mut list2 = LinkedList::from([1, 2, 3]);
```

* Update

```rust
// Push to the back
list1.push_back(5);
// Push to the front
list1.push_front(4);
// Pop the last item
*list.pop_back().unwrap();
// Pop the first item
*list.pop_front().unwrap();
```

* Useful methods

```rust
// Length of LinkedList
list.len();
// Get the last item
*list1.back().unwrap();
// Get the first item
*list1.front().unwrap();
```

* Iterate

```rust
// Not mutable
let mut iter = list.iter();
assert_eq!(iter.next(), Some(&0));
assert_eq!(iter.next(), Some(&1));
assert_eq!(iter.next(), Some(&2));
assert_eq!(iter.next(), None);
// Mutable
for element in list1.iter_mut() {
    *element += 10;
}
```

## Algorithm

* Compare

```rust
use std::cmp;
min_val = cmp::min(val1, val2);
min_val = cmp::max(val1, val2);
```

* Swap

```rust
use std::mem;

let mut x = 5;
let mut y = 42;

mem::swap(&mut x, &mut y);
```

* Range

```rust
use num::range;
// from 0 to 9
for n in range(0, 10) {}
for n in 0..10 {}
// reverse: from 9 to 0
for n in range(0, 10).rev() {}
// from 0 to 9, which step is 2
use num::range_step;
for n in range_step(0, 10, 2) {}
```

## Option

* `as_ref()`: To transform `&Option<T>` to `Option<&T>`
* `as_mut()`: To transform `&mut Option<T>` to `Option<&mut T>`
* `take()`: Takes the value out of the option, leaving None in its place
* `is_none()`: Check whether `Option<T> == None`
* `unwrap()`: Remove the Option. Note that `unwrap()` will move the value, i.e. node can't be used after `node.unwrap()`, you can use `node.as_mut().unwrap()` instead.

```rust
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
          next: None,
          val
        }
    }
}

impl Solution {
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            return None;
        }
        let mut h = head;  // since head is not mutable
        let mut node = h.as_mut().unwrap();  // node is the mutable reference of Box (h)
        while let Some(next_node) = node.next.as_mut() {  // next_node is the mutable reference of Box (node.next)
            if next_node.val == node.val {
                node.next = next_node.next.take();  // Move next_node.next to node.next and leave None to next_node.next
            } else {
                node = node.next.as_mut().unwrap(); // node is the mutable reference of Box (node.next)
            }
        }
        h
    }
    pub fn get_decimal_value(head: Option<Box<ListNode>>) -> i32 {
        let mut result = 0;
        let mut node = head;
        while let Some(content) = node.as_mut() {
            result = (result << 1) + content.val;
            node = content.next.take();
        }
        result
    }
}
```
