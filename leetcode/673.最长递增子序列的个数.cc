#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int ans_count;
    vector<int> memo;
    vector<int> count;
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // memo[i] 表示，以 nums[i] 结尾的最长递增子序列的长度。
        memo = vector<int>(n, 1);

        // count[i] 表示，以 nums[i] 结尾的最长递增子序列的 个数。
        count = vector<int>(n, 1);

        for (int i = 0; i < n; i++) {
            int ans = 0;
            int count_ans = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (ans < memo[j]) {
                        ans = memo[j];
                        memo[i] = ans + 1;
                        count_ans = count[j];
                    } else if (ans == memo[j]) {
                        count_ans += count[j];
                        // cout << "i = " << i << "j = " << j << "ans = " << ans << "memo[j] = " << memo[j] << "count_ans = " << count_ans << endl;
                    }
                }
                count[i] = count_ans;
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, memo[i]);
        }

        int count_ans = 0;
        for (int i = 0; i < n; i++) {
            if (ans == memo[i]) {
                count_ans += count[i];
            }
        }

    // for (int i = 0; i < n; i++) {
    //      cout << "nums[" << i << "] = " << nums[i] << " memo[" << i << "] = " << memo[i] << " count[" << i << "] = " << count[i] << endl;
    //}
    return count_ans;
    }
};