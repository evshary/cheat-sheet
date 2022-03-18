# vector
## Usage
We need to add `#include <vector>` first. Assume v is a vector for examples below.

* Access the element
  - `v[i]`: Access the ith element.
  - `v.at(i)`: Access the ith element, and throw exception if out of boundary.
  - `v.front()`: Return the first element of vector.
  - `v.back()`: Return the last element of vector.
* Add and Remove element
  - `v.push_back()`: Add element to the end of vector. Realloc the memory if necessary.
    * Don't rely on the auto memory management of push_back. Use reserve(), resize(), constructor instead.
  - `v.pop_back()`: Delete the last element of vector.
  - `v.insert()`: Insert elements into any location of vector.
    * `v.insert(v.begin()+3, 5)`: Insert "5" into vector v. The location will be 4th.
  - `v.erase()`: Remove elements from vector by the index.
    * `v.erase(v.begin(), v.end())`: Remove all the element.
    * `v.erase(v.begin()+2, v.begin()+4)`: Remove the element which index is from 2 to 3.
  - `v.clear()`: Clear all the elements.
* Get the length / capacity
  - `v.empty()`: Return true if vector is empty.
  - `v.size()`: Get the number of elements from vector.
    * Use `v.empty()` instead of `v.size()==0`, since size() may not always be O(1) for all containers.
  - `v.resize()`: Change the number of elements.
  - `v.capacity()`: Get the maximum size of vector. The capacity can only be increased.
  - `v.reserve()`: Increse the maximum size of vector.
* Iterator
  - `v.begin()`: Return a iterator which points to the first element.
  - `v.end()`: Return a iterator which points to the element next to the last element. (WARNING: not the last one)
  - `v.rbegin()`: Return a reverse iterator which points to the last element.
  - `v.rend()`: Return a reverse iterator which points to the element right before the first element. (WARNING: not the first one)
* erase-remove idiom: remove the element from vector
  - remove will move the matched element to the end of the vector, and erase will remove these elements.
```cpp
#include <algorithm>
// Remove 8 from vector v
v.erase(std::remove(v.begin(), v.end(), 8), v.end());
```

## Example
* Iterate
```c++
// Use index
for(int i=0; i<v.size(); i++) cout << v[i] << " ";
for(int i=0; i<v.size(); i++) cout << v.at(i) << " ";
// Simpler
for(auto i : v) cout << i << " ";
// Use iterator
vector<int>::iterator it_i;
for(it_i=ff.begin(); it_i!=ff.end(); ++it_i) cout << *it_i << " ";
vector<int>::reverse_iterator it_i;
for(it_i=ff.rbegin(); it_i!=ff.rend(); ++it_i) cout << *it_i << " ";
// Use auto
for(auto it=ff.begin(); it!=ff.end(); ++it) cout << *it << " ";
```
* Construction and Assignment
```c++
// Direct init vector (For C++ 11, need to add -std=c++11 for compilor option)
vector<int> vect{1, 2, 3};
// Init with constructor
vector v(5,0); // {0,0,0,0,0}
// Init from array
int array[] = {0,1,2,3,4};
vector<int> vect(array, array + 3); // Copy the first 3 element from array
// Init from vector
vector v1;
vector v2(v1.begin(), v1.end()); // Copy from v1
vector v2(v1.begin(), v1.begin()+3); // Copy the first 3 element from v1
```
* Init 2D array
```c++
// Init 2D array
vector<vector<int>> vect { { 11, 12, 13 },
                           { 21, 22, 23 } };
// Easier way: row 2 and col 3
vector<vector<int>> vect(2, vector<int>(3, 0));
// Use assign
vector<int> row;
row.assign(n,0); // Init an vector with n elements
vector<vector<int>> array2D;
array2D.assign(n,row);  // init an vector with n vectors 
```
* Fill
```c++
vector<int> v(8);
fill(v.begin(), v.end(), 8); // fill with 8
```
* Find max / min number
```c++
#include <algorithm>
vector<int> v{3,2,1,7,8,9};
int max_index = max_element(v.begin(), v.end()) - v.begin();
int max_element = *max_element(v.begin(), v.end());
int min_index = min_element(v.begin(), v.end()) - v.begin();
int min_element = *min_element(v.begin(), v.end());
```
* Find the specific number
```c++
#include <algorithm>
vector<int> v{3,2,1,7,8,9};
auto it = find(v.begin(), v.end(), 7);
if (it != v.end()) {
  cout << *it << " is at index " << it-v.begin() << endl;
}
```

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

int main(){
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

# map & unordered_map
## Usage
map & unordered_map is a key-value structure. It can be used as hash table.

We need to include files first.

* map: `#include <map>`
* unordered_map: `#include <unordered_map>`

The difference between them:

* map:
  - The internal data structure is a red-black tree, so search and insert is O(logN)
  - Ordered.
  - Higher space usage.
* unordered_map:
  - The internal data structure is a hash table, so lookup only needs O(1)
  - Building hash table takes time.

## Example
* insert
```c++
map<string, int> m;
// Use insert
m.insert(pair<string,int>("test1", 111));
// Insert directly
m["test2"] = 222;
// Count occurrence
if (m.find(1) == m.end())
    m[1] = 1;
else
    m[1]++;
```
* Iterate
```c++
unordered_map<string, string> maps;
for (auto it = maps.begin(); it != maps.end(); ++it)  
    cout << it->first << " " << it->second << endl;
// simpler way
for (auto m : maps)
    cout << m.first << " " << m.second << endl;
// more simpler way
for (auto [_, second] : maps)
    cout << second << endl;
```
* find
```c++
map<string,int>::iterator it = m.find("test1");
if(it != m.end())
    cout << "Value is " << it->second << endl;
else
    cout << "Not found." << endl;
```
* delete
```c++
// Find first then erase
map<string,int>::iterator it = m.find("test1");
m.erase(it);
// Erase directly
int ret = erase("test2");  // Return 1 while deleted, or return 0.
// Erase all map
m.erase(m.begin(), m.end());
m.clear();
```
* sort: Transform into vector and then sort it
```c++
bool comp(pair<int,int> l, pair<int,int> r) {
    return r.second < l.second;
}
unordered_map<int,int> htable; // or map<int,int> is the same
// 1st way to transform into vector
vector<pair<int,int>> sort_result;
for (auto i : htable) sort_result.push_back(i);
// 2nd way to transform into vector
vector<pair<int,int>> sort_result2(htable.begin(), htable.end());
sort(sort_result.begin(), sort_result.end(), comp);
```

# stack
```c++
#include <stack>
using namespace std;

int main(){
  stack<int> s;
  s.push(1); // [1]
  s.push(2); // [2,1]
  s.push(3); // [3,2,1]
  for(int i=0; i < s.size() ; i++) {
    cout << s.top() << endl; // output 3 2 1
    s.pop();
  }
  return 0;
}
```

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

# pair
* Generate pair
```c++
vector<int> v1{1,2,3,4,5};
vector<int> v2{11,22,33,44,55};
vector<pair<int,int>> vp;
for (int i = 0; i < v1.size(); i++) {
  vp.push_back(make_pair(v1[i], v2[i]));
}
```
* Simpler to generate and read pair
```c++
vector<pair<int,int>> vp;
vp.push_back({1,2});
vp.push_back({3,4});
for (auto [x,y] : pairs) {
    cout << x << " " << y << endl;
}
```
* sort
```c++
// sort with first element
sort(result.begin(), result.end());
// sort with second element
bool compare_func(pair<int,int> &num1, pair<int,int> &num2){
  if (num1.second < num2.second)
    return true;
  else
    return false;
}
sort(result.begin(), result.end(), compare_func);
```

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
