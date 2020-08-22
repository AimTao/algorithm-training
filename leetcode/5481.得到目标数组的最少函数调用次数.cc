#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < n; i++) {
            q.push_back(nums[i]);
        }
        int min_ans = 0;
        while (n) {
            for (int i = 0; i < n; i++) {
                if (q[i] % 2 != 0) {
                    min_ans++;
                    q[i]--;
                }
            }
            while(!q.front()) {
                q.pop_front();
            }
            n = q.size();
            if (n == 0) {
                break;
            }
            for (int i = 0; i < n; i++) {
                q[i] /= 2;
            }
            min_ans++;
        }
        return min_ans; 
    }
};