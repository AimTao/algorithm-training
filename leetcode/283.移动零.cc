#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return;
    }
};