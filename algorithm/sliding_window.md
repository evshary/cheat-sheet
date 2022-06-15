# Sliding Window

There are 4 important things here:

1. Update window structure (right)
2. Shrink window condition
3. Update window structure (left)
4. Update result (might not b here)

```cpp
int left = 0, right = 0;
while (right < arr.size()) {
    char c = arr[right];
    right++;
    // Update window structure (right)
    while (shrink window condition) {  // Shrink window condition
        char old_c = arr[left];
        left++;
        // Update window structure (left)
    }
    // Update result (might not b here)
}
```
