#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans(2, 0);
    unordered_map<int, int> m(n);
    for (int i = 0; i < n; i++) {
        m[nums[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        int tmp = target - nums[i];
        if (m.count(tmp) && m[tmp] != i) {
            ans[0] = i;
            ans[1] = m[tmp];
            return ans;
        }
    }
    return ans;
}