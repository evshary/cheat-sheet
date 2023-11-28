# deque

deque means double-ended queue, which can insert/delete node on the head/end of the queue.

# Usage

We need to add `#include <deque>` before using deque.

* `q.push_back(element)`: Put the element to the end of the queue.
* `q.push_front(element)`: Put the element to the head of the queue.
* `q.pop_back()`: Remove the last element.
* `q.pop_front()`: Remove the first element.
* `q.size()`: Return the size of the queue.
* `q.empty()`: Reture whether the queue is empty or not.
* `q.front()`: Get the value of the head of the queue.
* `q.back()`: Get the value of the end of the queue.

## Example

```c++
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> d{1,2,3,4};
    cout << "We'll remove " << d.front() << endl;
    d.pop_front();   // [2,3,4]
    d.push_front(9); // [9,2,3,4]
    cout << "We'll remove " << d.back() << endl;
    d.pop_back();    // [9,2,3]
    d.push_back(10); // [9,2,3,10]
    for (auto n : d) {
        cout << n << endl;
    }
    
    return 0;
}
```

# Reference

* [C++ std::deque 用法與範例](https://shengyu7697.github.io/std-deque/)
