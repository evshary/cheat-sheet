# atom
* Need to `#include <atomic>`
* There are atomic load and store.
* memory_order
  - memory_order_relaxed: Only ensure atomic operation.
  - memory_order_seq_cst: Order the instructions of all the threads based on the atomic operations.

## Example
```c++
#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> global_num(0);

void set_thread(int x) {
  global_num.store(x,std::memory_order_relaxed);
}

void load_thread() {
  int x = 0;
  do {
    x = global_num.load(std::memory_order_relaxed);
  } while(x == 0);
  std::cout << "global_num: " << x << endl;
}

int main ()
{
  std::thread t1(load_thread);
  std::thread t2(set_thread, 1);
  t1.join();
  t2.join();
  return 0;
}
```

## Reference
* [std::atomic::store](http://www.cplusplus.com/reference/atomic/atomic/store/)
* [std::atomic::load](http://www.cplusplus.com/reference/atomic/atomic/load/)
* [std::memory_order](http://www.cplusplus.com/reference/atomic/memory_order/)
