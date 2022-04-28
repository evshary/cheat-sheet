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
vector<pair<int,int>> vp{
    {2,2},
    {3,1},
    {1,3},
};
// sort with first element (small -> big): will become {1,3},{2,2},{3,1}
sort(vp.begin(), vp.end());
// sort with second element (small -> big): will become {3,1},{2,2},{1,3}
bool compare_func(pair<int,int> &num1, pair<int,int> &num2){
  if (num1.second < num2.second)
    return true;
  else
    return false;
}
sort(vp.begin(), vp.end(), compare_func);
```
