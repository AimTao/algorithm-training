#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) {
        return 0;
    }
    if (size == 1) {
        return nums[0];
    }
    if (size == 2) {
        return max(nums[0], nums[1]);
    }
    vector<int> memo(size, -1);
    memo[0] = nums[0];
    memo[1] = max(nums[0], nums[1]);
    for (int i =2; i < size; i++) {
        memo[i] = max((memo[i - 2] + nums[i]), memo[i - 1]);
    }
    return memo[size - 1];
}