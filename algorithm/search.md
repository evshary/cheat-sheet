# Binary Search

```c++
int left = 0;
int right = nums.size() - 1;

while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        return mid;  // note
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else if (nums[mid] > target) {
        right = mid - 1;
    }
}
return -1;  // note
```

# Left Bound

```c++
int left = 0;
int right = nums.size() - 1;

while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        right = mid - 1;  // note
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else if (nums[mid] > target) {
        right = mid - 1;
    }
}
// note
if (left >= nums.size() || nums[left] != target)
    return -1;
return left;
```

# Right Bound

```bash
int left = 0;
int right = nums.size() - 1;

while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        left = mid + 1;  // note
    } else if (nums[mid] < target) {
        left = mid + 1;
    } else if (nums[mid] > target) {
        right = mid - 1;
    }
}
// note
if (right < 0 || nums[right] != target)
    return -1;
return right;
```

