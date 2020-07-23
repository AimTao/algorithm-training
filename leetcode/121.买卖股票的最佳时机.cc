#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n == 0) {
            return 0;
        }
        int min = prices[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                res = max(prices[i] - min, res);
            }
        }
        return res;
    }
};