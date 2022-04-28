# set & unordered_set

We need to include files first.

* set: `#include <set>`
* unordered_set: `#include <unordered_set>`

## set

```c++
#include <set>
using namespace std;

set<int> s;
s.insert(2); // {2}
s.insert(1); // {1,2}
s.insert(3); // {1,2,3}
// iterate
for (auto e : s) {
    cout << e << endl;
}
// Check exist or not
if (s.count(2)) {
    // Since s.count(2) == 1, enter here.
}
s.erase(2); // {1,3}
if (s.count(2)) {
    // Since s.count(2) == 0, ignore here.
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
// iterate
for (auto e : u) {
    cout << e << endl;
}
// Check exist or not
if (u.count(2)) { 
    // Since u.count(2) == 1, enter here.
}
// To erase, worst case is O(N). Refer to https://stackoverflow.com/questions/34556937/stdunordered-seterase-complexity
u.erase(2);
if (u.count(2)) {
    // Since u.count(2) == 0, ignore here.
}
```

# find

* Find whether the value exist or not, but we can often use count instead of find.

```c++
// find value in the set
set<int>::const_iterator it = s.find(2);  // or auto it = u.find(2)
if (it == s.end())
    cout << "Not found" << endl;
else
    cout << *it << "is here" << endl;

// find value in the unordered_set
unordered_set<int>::const_iterator it = u.find(2);  // or auto it = u.find(2)
if (it == u.end())
    cout << "Not found" << endl;
else
    cout << *it << "is here" << endl;
```

# vector <=> set

```c++
vector<int> v{1,2,3,3,4,4};
set<int> s(v.begin(), v.end());
unordered_set<int> u(v.begin(), v.end());
vector<int> set_v(s.begin(), s.end());
unordered_set<int> uset_v(s.begin(), s.end());
```
