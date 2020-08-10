#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> ans;
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!q.empty() && q.front() < i - k + 1) {
            q.pop_front();
        }
        count ++;
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        q.push_back(i);
        
        if (count >= k) {
            ans.push_back(nums[q.front()]);
        }
    }
    return ans;
}