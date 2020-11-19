#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        // memo[i] 表示：最长子序列长度为 i 的序列最后一个的 num 的值
        vector<int> memo(n + 1, 0);
        int len = 1;
        memo[len] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > memo[len]) {
                len++;
                memo[len] = nums[i];
            } else {
                int mid, l = 1, r = len, pos = 0;
                while(r >= l) {
                    mid = (r + l) >> 1;
                    if (nums[i] > memo[mid]) {
                        l = mid + 1;
                        pos = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                memo[pos + 1] = nums[i];
            }
        }
        return len;
    }
};