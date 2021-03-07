#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int size = nums.size();
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            sum += (long long) nums[i];
        }
        sum = abs((long long) goal - sum);
        
        if (sum == 0) {
            return 0;
        }
        
        // cout << "sum = " << sum << endl;
        
        long long ans = 1;
        while (sum > limit) {
            long long d = sum / limit;
            //cout << "d = " << d << endl;
            sum = sum % limit;
            if (sum != 0) {
                ans += d;
            } else {
                ans = d;
            }
        }
        return ans;
    }
};