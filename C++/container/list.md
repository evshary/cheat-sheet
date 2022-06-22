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

# Example

```c++
void showList(list<int>& l) {
    for (auto n : l) {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    list<int> l{1,5,3,9};
    cout << "Init the list" << endl;
    showList(l);  // [1 5 3 9]
    cout << "Add number in the head and end" << endl;
    l.push_front(0);
    l.push_back(100);
    showList(l);  // [0 1 5 3 9 100]
    cout << "Insert 99 in index 2" << endl;
    auto it = l.begin();
    it++;
    it++;
    l.insert(it, 99);
    showList(l);  // [0 1 99 5 3 9 100]
    cout << "Insert 2 98 after 99" << endl;
    l.insert(it, 2, 98);
    showList(l);  // [0 1 99 98 98 5 3 9 100]
    cout << "Remove all 98" << endl;
    l.remove(98);
    showList(l);  // [0 1 99 5 3 9 100]
    cout << "Sort list" << endl;
    l.sort();
    showList(l);  // [0 1 3 5 9 99 100]
    cout << "Reverse list" << endl;
    l.reverse();
    showList(l);  // [100 99 9 5 3 1 0]
    cout << "Remove the 2nd number" << endl;
    it = l.begin();
    it++;
    l.erase(it);
    showList(l);  // [100 9 5 3 1 0]
    cout << "Clear the list" << endl;
    l.clear();
    showList(l);  // []

    return 0;
}
```