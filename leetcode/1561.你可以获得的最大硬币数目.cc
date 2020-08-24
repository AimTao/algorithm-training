#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool com(const int& a, const int& b) const {
        return a > b;
    }
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.begin(), piles.end());
        int n = piles.size();
        for (int i = n - 1; i > n / 3 -1; i -= 2) {
            ans += piles[i - 1];
        }
        return ans;
    }
};