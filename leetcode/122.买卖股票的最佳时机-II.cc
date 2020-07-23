#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        vector<int> memo(n + 1, 0);
        memo[0] = 0;
        memo[1] = 0;
        for (int i = 2; i <= n; i++) {
            memo[i] = prices[i - 1] > prices[i -2] ? memo[i - 1] + prices[i - 1] - prices[i - 2] : memo[i - 1];
        }
        return memo[n];
}