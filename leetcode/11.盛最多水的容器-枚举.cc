#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int ans = (j - i) * max(height[i], height[j]);
                max_ans = max(max_ans, ans);
            }
        }
        return max_ans;
    }
};