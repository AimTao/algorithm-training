#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector< vector<int> > ans;
    vector<int> tmp_ans(3);
    for (int k = 0; k < n - 2; k++) {
        if (nums[k] > 0) {
            break;
        }
        if (k > 0 && nums[k] == nums[k - 1]) {
            continue;
        }
        for (int i = k + 1, j = n - 1; i < j;) {
            if (i > k + 1 && nums[i] == nums[i + 1]) {
                i++;
                continue;
            }
            if (j < n - 1 && nums[j] == nums[j - 1]) {
                j--;
                continue;
            }
            int sum = nums[k] + nums[i] + nums[j];
            if (sum < 0) {
                i++;
            } else if (sum > 0) {
                j--;
            } else {
                tmp_ans[0] = nums[k];
                tmp_ans[1] = nums[i];
                tmp_ans[2] = nums[j];
                ans.push_back(tmp_ans);
                i++;
                j--;
            }
        }
    }
    return ans;
}