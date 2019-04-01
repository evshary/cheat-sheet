1. The quick sort uses pivot and recursion to get small and big part.
2. We should not forget the terminal condition, i.e. start >= end.
3. We can't write as the following
`while(j > start && nums[j] > nums[pivot]) j--;`, or we will go into infinite loop while array is composed of the same number, like [7,7,7,7,7,7].