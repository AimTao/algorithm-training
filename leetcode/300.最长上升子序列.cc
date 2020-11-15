#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // memo[i] 状态表示：以 nums[i] 结尾的最长上升子序列 的长度。
        vector<int> memo(n, 1);
        for (int i = 0; i < n; i++) {
            int tmp_ans = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && tmp_ans < memo[j]) {
                    memo[i] = memo[j] + 1;
                    tmp_ans = memo[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, memo[i]);
        }
        return ans;
    }
};