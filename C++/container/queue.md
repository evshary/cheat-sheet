# queue

## Usage

We need to add `#include <queue>` first. Assume q is a queue for examples below.

* `q.push(element)`: Add element to the end of q.
* `q.pop()`: Remove the first element in q.
* `q.back()`: Get the value of the last element in q.
* `q.front()`: Get the value of the first element in q.
* `q.empty()`: Check whether there is any element in q.

## Example

```c++
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(5);  // [5]
    q.push(10); // [5,10]
    q.push(15); // [5,10,15]
    q.pop();    // [10,15]

    cout << q.size() << endl;  // output: 2
    cout << q.back() << endl;  // output: 15
    cout << q.front() << endl; // output: 10
}
```

# priority_queue

## Usage

We need to add `#include <queue>` first. Assume q is a queue for examples below.

priority_queue is a queue that the highest priority element is extracted first.

Default is that the largest value has the highest priority.

* Declaration:
  - `priority_queue<int> pqueue;`: Default is largest value first.
  - `priority_queue<int,vector<int>,less<int>>`: Largest value first.
  - `priority_queue<int,vector<int>,greater<int>>`: Smallest value first.
  - `priority_queue<pair<int,int>>`: Default is to sort the 1st element of the pair from big to small.
* Operations:
  - `q.push(element)`: Put element into q. Time complexity is O(NlogN).
  - `q.pop()`: Take the highest priority element from queue and delete.
  - `q.top()`: Read the value of element which has highest priority.
  - `q.empty()`: Check whether the q is empty or not.
  - `q.size()`: Return the current number of elements.
* Implement compare functions

```c++
#include <queue>
#include <vector>
#include <iostream>

template<class T>
void printQueue(T& q) {
    while (!q.empty()) {
        std::cout << q.top() << std::endl;
        q.pop();
    }
}

int main() {
    auto cmp = [](int a, int b) { return a < b; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> myqueue(cmp);
    for (int n : {5,2,3,1,9})
        myqueue.push(n);
    printQueue(myqueue);
    return 0;
}
```
