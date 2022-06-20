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

# Two Pointers

* 4sum:
  - 18: https://leetcode.com/problems/4sum/
* Reverse Linked List:
  - 206: https://leetcode.com/problems/reverse-linked-list/
* Fast Slow Pointers:
  - 19: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
  - 142: https://leetcode.com/problems/linked-list-cycle-ii/
* Reverse String
  - 151(SC should be O(1)): https://leetcode.com/problems/reverse-words-in-a-string/

# Stack & Queue

* Stack Match Problem
  - 20: https://leetcode.com/problems/valid-parentheses/
  - 1047: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
* Expression
  - 150: https://leetcode.com/problems/evaluate-reverse-polish-notation/
* Monotonic Queue
  - 239: https://leetcode.com/problems/sliding-window-maximum/
* Priority Queue
  - 347: https://leetcode.com/problems/top-k-frequent-elements/

# Tree

* Traverse with recursion in 3 steps
  - What is the return value and argument
  - End condtion
  - The logic of every layer
* Traverse without recursion
  - https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.md
* How to traverse:
  - preorder, inorder, postorder
  - by layer:
    - 102: https://leetcode.com/problems/binary-tree-level-order-traversal/
* Tree attribute:
  - 101: https://leetcode.com/problems/symmetric-tree/
  - 404: https://leetcode.com/problems/sum-of-left-leaves/
  - 513: https://leetcode.com/problems/find-bottom-left-tree-value/
* Modify Tree:
  - 106: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
  - 654: https://leetcode.com/problems/maximum-binary-tree/
* Binary Search Tree attribute
  - 700: https://leetcode.com/problems/search-in-a-binary-search-tree/
  - 98: https://leetcode.com/problems/validate-binary-search-tree/
* Modify Binary Search Tree
  - 701: https://leetcode.com/problems/insert-into-a-binary-search-tree/
  - 450: https://leetcode.com/problems/delete-node-in-a-bst/

# Graph

## Adjacent List

* 207: https://leetcode.com/problems/course-schedule/

## DFS

* 399: https://leetcode.com/problems/evaluate-division/

## BFS

* Review:
  - Not to remember steps:
    - 200: https://leetcode.com/problems/number-of-islands/
  - Remember steps:
    - 994: https://leetcode.com/problems/rotting-oranges/
* Template

```c++
queue<Node> q;
unordered_set<Node> s;
int step = 0;
q.push(root);
s.insert(root);
while (!q.empty()) {
    step++;
    int cur_step_size = q.size();
    for (int i = 0; i < cur_step_size; i++) {
        Node *n = q.front(); q.pop();
        if (/*n is target*/) return step;
        for (/*All the neighbors*/) {
            if (!s.count(neighbor)) {
                q.push(neighbors);
                s.insert(neighbor);
            }
        }
    }
}
return -1;
```

* Reference: https://blog.techbridge.cc/2019/12/21/leetcode-%E5%88%B7%E9%A1%8C-pattern-breadth-first-search/

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
  - 組合問題：
    - 77: https://leetcode.com/problems/combinations/
  - 切割問題：
    - 131: https://leetcode.com/problems/palindrome-partitioning
  - 子集問題：
    - 78 (重點取或不取): https://leetcode.com/problems/subsets/
  - 排列問題：
    - 46: https://leetcode.com/problems/permutations/
  - 棋盤問題：
    - 51: https://leetcode.com/problems/n-queens/
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
  * Medium:
    - 376: https://leetcode.com/problems/wiggle-subsequence/
  * Not easy to think of
    - 45: https://leetcode.com/problems/jump-game-ii/
    - 452: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
  * 2 dimension
    - 406: https://leetcode.com/problems/queue-reconstruction-by-height/

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
  - Basic: 
    - 70(Climbing stairs): https://leetcode.com/problems/climbing-stairs/
  - 0-1 Knapsack:
    - 416: https://leetcode.com/problems/partition-equal-subset-sum
  - Complete knapsack:
    - 518: https://leetcode.com/problems/coin-change-2/
    - 377: https://leetcode.com/problems/combination-sum-iv/
  - Robber:
    - 198: https://leetcode.com/problems/house-robber/
  - Stock:
    - 122: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
  - Subsequence:
    - 1143: https://leetcode.com/problems/longest-common-subsequence/
    - 72: https://leetcode.com/problems/edit-distance/
    - 516: https://leetcode.com/problems/longest-palindromic-subsequence/

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

# Reference

* [[徵文] 北美SDE 刷題/系統設計準備經驗](https://www.ptt.cc/bbs/Oversea_Job/M.1648404462.A.A04.html)
* [LeetCode 刷题攻略](https://github.com/youngyangyang04/leetcode-master)：Very good resource
 