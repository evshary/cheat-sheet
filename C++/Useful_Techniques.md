# Useful Techniques

Here we list some useful techniques in C++:

# Use swap instead of assign

swap is in `#include <utility>` but we don't need to include it.

Refer to [Faster to swap or assign a vector of strings?](https://stackoverflow.com/questions/22001854/faster-to-swap-or-assign-a-vector-of-strings)

```c++
vector<string> temp;
v = temp;         // complexity is linear in the size of the temp
v.swap(temp);     // complexity is constant
//swap(v, temp);  // another way
```

# Elegant way to run DFS

```c++
int dirs[5] = {0, 1, 0, -1, 0};
// If maze is N x N
vector<vector<int>> maze(N, vector<int>(N, 0));
// This is current posistion
int x, y;
for (int d = 0; d < 4; d++) {
	int r = x + dirs[d];
	int c = y + dirs[d+1];
	if (min(r, c) >= 0 && max(r, c) < maze.size()) {
		// do something to available neighbor r and c
	}
}
```

# Use emplace instead of push (Actually compiler will optimize it for you)

push will initialize the temporary variable and then push into stack,
while emplace will call constructor directly

Ref: https://www.gushiciku.cn/pl/gxZH/zh-tw

```c++
vector<pair<string,int>> v;
v.push_back({"abc", 123});
v.emplace_back("def", 456);
for (auto & [s, i] : v) {
    cout << s << " " << i << endl;
}
```

# Exchange

`int z = std::exchange(x, y);` means

1. x is assigned the value of y,
2. z is assigned the value that x had initially.

```c++
#include <utility>
int a = 1;
int b = 2;
b = std::exchange(a, b);
```
