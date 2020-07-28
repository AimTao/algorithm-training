#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> ans = nums;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] + ans[i];
    }
    return ans;
}