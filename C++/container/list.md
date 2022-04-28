# list

* push
```c++
#include <list>

list<int> l;
l.push_back(2);  // [2]
l.push_back(3);  // [2,3]
l.push_front(1); // [1,2,3]
```

* iterate
```c++
list<int>::iterator it;
for (it = l.begin(); it != l.end(); ++it) 
  cout << *it << " ";
// reverse
list<int>::reverse_iterator rit;
for (rit = l.rbegin(); rit != l.rend(); rit++)
  cout << *rit << " ";
```

* remove & erase
  - remove is to delete the same value of the element.
  - erase is to delete the same pointer of the element.
```c++
list<int> l;
// WARNING: We can't remove/erase before ++. This will go wrong.
for (auto it = l.begin(); it != l.end();) {
  auto pit = it++; // record the previous element first
  // erase
  // l.erase(pit);
  // remove
  // l.remove(*pit);
}
```
