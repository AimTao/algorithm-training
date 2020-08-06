#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size(), ans = 0, max_ans = nums[0];
    for (int i = 0; i < n; i++) {
        ans = max(ans + nums[i], nums[i]);
        max_ans = max(max_ans, ans);
    }
    return max_ans;
}