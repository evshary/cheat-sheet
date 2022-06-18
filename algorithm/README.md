# Flow

* Ask the detail of problems (e.g. limitation)
* Take an example if necessary
* Find the brute force solution and give the complexity
* Find out how to optimize, e.g. DP, memoization...
* Write down the program
* Run some examples and don't forget corner case

# Basic C++ container review

Refer to https://github.com/evshary/cheat-sheet/tree/main/C%2B%2B/container

**Important: vector, unordered_map, queue, deque, pair**

# Array

* Sliding Window
  - Template: https://github.com/evshary/cheat-sheet/blob/main/algorithm/sliding_window.md
  - Review: 209 https://leetcode.com/problems/minimum-size-subarray-sum/
* Binary Search
  - Template: https://github.com/evshary/cheat-sheet/blob/main/algorithm/search.md
  - Review: 704 https://leetcode.com/problems/binary-search/

# Backtracking

* Backtracking use recursive funtion to do brute-force
* Suitable to these question
  - 組合問題：N個數中找出k個數的集合
  - 切割問題：有幾種切割方式
  - 子集問題：集合中有幾個符合條件的子集
  - 排列問題：N個數有幾種排列方式
  - 棋盤問題：N皇后、解數獨
* 4 steps
  - Write recursive function: `void backtracking(ARGUMENT)`
    - Don't need to add argument first
  - Write end condition
  - How to do traverse
  - You can do "pruning" to optimize the algorithm.
* Review:
  - All: https://leetcode.com/tag/backtracking/
  - 組合問題：77
  - 切割問題：131
  - 子集問題：78 (重點取或不取)
  - 排列問題：46
  - 棋盤問題：51
* Template

```c++
void backtracking(ARGUMENT) {
    if ( /* end condition */ ) {
        // save result
        return;
    }
    for (ALL CHOICES) { // You can add pruning here
        // Processing choice
        backtracking(CHOICE);
        // Undo processing
    }
}
```

# Greedy

No fixed step-by-step tutorial.
You can try to find counter example to see whether the logic is correct.

* Review:
  * Easy:
    - 455 https://leetcode.com/problems/assign-cookies/

# Dynamic Programming

* Dynamic Programming 5 steps
  - Setup DP table and its meaning
  - Find the DP formula
  - Initialize DP table
  - Traverse order
  - Take an example
* The kinds of DP programming
  - Knapsack (0-1 knapsack, complete knapsack)
  - Robber
  - Stock
  - Subsequence
* Review:
  - All: https://leetcode.com/tag/dynamic-programming/
  - Basic: 70(Climbing stairs)
  - 0-1 Knapsack: 416
  - Complete knapsack: 518, 377
  - Robber: 29
  - Stock: 122
  - Subsequence: 44, 72, 516

## 0-1 knapsack template

Every object only has 1.
Find the largest value in the bag while total weight is limited.

```c++
vector<int> wieght = {1, 3, 4};
vector<int> value = {15, 20, 30};
int bagweight = 4;

vector<int> dp(bagweight+1);
for (int i = 0; i < weight.size(); i++) {  // Iterate all the objects
    for (int j = bagweight; j >= weight[i]; j--) {  // Traverse the weight from big to small 
        dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
    }
}
```

## complete knapsack template

Every object is unlimited.
Find the largest value in the bag while total weight is limited.

Note that the iterating order has different meanings.


```c++
vector<int> wieght = {1, 3, 4};
vector<int> value = {15, 20, 30};
int bagweight = 4;

// Combinations: First object and then weight
vector<int> dp(bagweight+1);
for (int i = 0; i < weight.size(); i++) {  // Iterate all the objects
    for (int j = weight[i]; j <= bagweight; j++) {  // Traverse the weight from small to big
        dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
    }
}

// Permutations: First weight and then object
vector<int> dp(bagweight+1);
for (int j = 0; j <= bagweight; j++) {  // Iterate weight
    for (int i = 0; i < weight.size(); i++) {  // Iterate all the objects
        if (j >= weight[i]) dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
    }
}
```
