#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        if (n == 2) {
            return prices[1] > prices[0] ? prices[1] - prices[0] : 0;
        }
        int key = 0;
        vector<int> memo(n + 1, 0);
        memo[0] = 0;
        memo[1] = 0;
        if (prices[1] > prices[0]) {
            memo[2] = prices[1] - prices[0];
            key = prices[1];
        } else {
            memo[2] = 0;
            key = prices[0];
        }
        for (int i = 3; i <= n; i++) {
            if (prices[i - 1] > key) {
                memo[i] = memo[i - 1] + prices[i - 1] - key;
                key = prices[i - 1];
            } else {
                memo[i] = memo[i - 1];
            }
            int tmp = memo[i - 3] + prices[i - 1] - prices[i - 2];
            if (tmp > memo[i]) {
                key = prices[i - 1];
                memo[i] = tmp;
            }
        }
        return memo[n];
    }
};