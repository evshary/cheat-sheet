#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define BUCKET_SIZE 1000

void bucket_sort(vector<int>& nums) {
    int min_num = INT_MAX, max_num = INT_MIN;
    for (auto n : nums) {
    	min_num = min(min_num, n);
    	max_num = max(max_num, n);
    }
    int bucket_num = (max_num - min_num + 1)/BUCKET_SIZE + 1;
    vector<vector<int>> buckets(bucket_num);
    for (auto n : nums) {
    	buckets[(n - min_num)/BUCKET_SIZE].push_back(n);
    }
    int idx = 0;
    for (int i = 0; i < bucket_num; i++) {
    	sort(buckets[i].begin(), buckets[i].end());
    	for (int j = 0; j < buckets[i].size(); j++) {
            nums[idx++] = buckets[i][j];
    	}
    }
}

int main() {
    vector<vector<int>> test_cases{{5,1,-5,0,8,4,2,3,4},
                                   {1,4,6,4,11,3,-1,3,0},
                                   {0},
                                   {7,7,7,7,7,7,7,7},
                                   {9,8,7,6,5,4,3,2,1},
                                  };
    for (auto test_case : test_cases) {
        bucket_sort(test_case);
        for (auto i : test_case)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}