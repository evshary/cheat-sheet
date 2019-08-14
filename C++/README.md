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
  - `v.erase()`: Remove elements from vector.
    * `v.erase(vec.begin(), vec.end())`: Remove all the element.
    * `v.erase(vec.begin()+2, vec.begin()+4)`: Remove the element which index is from 2 to 3.
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

## Example
* Iterate
```c++
// Use index
for(int i=0; i<v.size(); i++) cout << v[i] << " ";
for(int i=0; i<v.size(); i++) cout << v.at(i) << " ";
// Use iterator
vector<int>::iterator it_i;
for(it_i=ff.begin(); it_i!=ff.end(); ++it_i) cout << *it_i << " ";
vector<int>::reverse_iterator it_i;
for(it_i=ff.rbegin(); it_i!=ff.rend(); ++it_i) cout << *it_i << " ";
/// Use auto
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

# queue
## Usage
We need to add `#include <queue>` first. Assume q is a queue for examples below.

* `q.push(element)`: Add element to the end of q.
* `q.pop()`: Remove the first element in q.
* `q.back()`: Get the value of the last element in q.
* `q.front()`: Get the value of the first element in q.

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