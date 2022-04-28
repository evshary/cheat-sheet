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

* init and size
```c++
unordered_map<char, char>
        n{ { 'A', 'G' },
           { 'B', 'E' },
           { 'C', 'E' },
           { 'D', 'K' },
           { 'E', 'S' } };
cout << n.size() << endl;  // will be 5
```

* insert
```c++
map<string, int> m;
// Use insert
m.insert(pair<string,int>("test1", 111));
// Insert directly
m["test2"] = 222;
// In fact, if the key does not exist, it'll initialize as 0
// Refer to https://stackoverflow.com/questions/62495482/what-does-unordered-map-returns-when-looking-for-a-key-that-doesnt-exist
m["not_exist_key"]++;  // m["not_exist_key"]=1
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

* find & count
```c++
// find
map<string,int>::iterator it = m.find("test1");
if(it != m.end())
    cout << "Value is " << it->second << endl;
else
    cout << "Not found." << endl;
// count (Just check exist or not)
if (m.count("test1"))
    cout << "Value found" << endl;
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
// Use second value to sort from small to big
bool comp(pair<int,int> l, pair<int,int> r) {
    return r.second < l.second;
}
unordered_map<int,int> htable; // or map<int,int> is the same
// 1st way to transform into vector
vector<pair<int,int>> sort_result;
for (auto i : htable) sort_result.push_back(i);
// 2nd way to transform into vector
vector<pair<int,int>> sort_result2(htable.begin(), htable.end());
// sort the vector
sort(sort_result.begin(), sort_result.end(), comp);
```
