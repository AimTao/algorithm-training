#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return nums[0];
    }
    vector<int> memo_1(n+1, 0);
    vector<int> memo_2(n+1, 0);
    // 求解memo_1[n - 3]
    memo_1[0] = 0;
    memo_1[1] = nums[0];
    memo_1[2] = max(nums[0], nums[1]);
    for (int i = 3; i <= n - 1; i++) {
        memo_1[i] = max(memo_1[i - 1], memo_1[i - 2] + nums[i - 1]);
    }
    // 求解memo_2[n - 2]
    memo_2[0] = 0;
    memo_2[1] = 0;
    memo_2[2] = nums[1];
    for (int i = 3; i <= n; i++) {
        memo_2[i] = max(memo_2[i - 1], memo_2[i - 2] + nums[i - 1]);
    }

    return max(memo_2[n], memo_1[n - 1]);
}
