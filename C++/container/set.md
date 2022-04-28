# set & unordered_set

## set

```c++
#include <set>
using namespace std;

int main(){
  set<int> s;
  s.insert(2); // {2}
  s.insert(1); // {1,2}
  s.insert(3); // {1,2,3}
  if (s.count(2)) {
    // Since s.count(2) == 1, enter here.
  }

  s.erase(2); // {1,3}
  if (s.count(2)) {
    // Since s.count(2) == 0, ignore here.
  }
}
```

## unordered_set

unordered_set uses hash table so it's unordered.

```c++
#include <unordered_set>
using namespace std;

unordered_set<int> u;
u.insert(1);
u.insert(2);
unordered_set<int>::const_iterator it = u.find(2);
if (it == u.end())
  cout << "Not found" << endl;
else
  cout << *it << "is here" << endl;
// To erase, worst case is O(N). Refer to https://stackoverflow.com/questions/34556937/stdunordered-seterase-complexity
u.erase(2);
```
