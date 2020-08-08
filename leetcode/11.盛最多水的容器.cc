#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
       int max_ans = 0;
       int n = height.size();
       for (int i = 0, j = n - 1; i < j; ) {
           int min_height = height[i] > height[j] ? height[j--] : height[i++];
           int ans = (j - i + 1) * min_height;
           max_ans = max(ans, max_ans);
       }
       return max_ans;
    }
};