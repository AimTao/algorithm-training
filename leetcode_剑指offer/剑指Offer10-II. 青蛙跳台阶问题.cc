#include <vector>
using namespace std;

class Solution {
public:
    int  fun(int n, vector<int> &memo) {
        if (n == 0 || n == 1) {
            memo[n] = 1;
            return 1;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        memo[n] = (fun(n - 1, memo) % 1000000007 + fun(n - 2, memo) % 1000000007) % 1000000007;
        return memo[n];
    }
    int numWays(int n) {
        vector<int> memo(n+1, -1);
        memo[n] = fun(n, memo);
        return memo[n];
    }
};