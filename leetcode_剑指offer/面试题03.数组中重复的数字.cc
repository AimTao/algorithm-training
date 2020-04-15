#include <bits/stdc++.h>
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
		int n = nums.size();
		vector<bool> flag(n, false);
		for (int i = 0; i < n; i++) {
			if (!flag[nums[i]]) {
				flag[nums[i]] = true;
			}
			else {
				return nums[i];
			}
		}
		return -1;
    }
};