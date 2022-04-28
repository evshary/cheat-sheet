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
