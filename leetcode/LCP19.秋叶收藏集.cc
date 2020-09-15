#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumOperations(string leaves) {
        int leaves_size = leaves.size();
        vector< vector<int> > dp(leaves_size, vector<int>(3, 0));
        for (int i = 0; i < leaves_size; i++) {
            // 红
            if (i < 1) {
                dp[i][0] = (leaves[i] == 'r' ? 0 : 1);
            } else {
                dp[i][0] = dp[i - 1][0] + (leaves[i] == 'r' ? 0 : 1);
            }
            
            // 红黄
            if (i < 1) {
                dp[i][1] = dp[i][0];
            } else {
                dp[i][1] = min(dp[i - 1][1] + (leaves[i] == 'y' ? 0 : 1), dp[i - 1][0] + (leaves[i] == 'y' ? 0 : 1));
            }

            // 红黄红
            if (i < 2) {
                dp[i][2] = dp[i][1];
            } else {
                dp[i][2] = min(dp[i - 1][1] + (leaves[i] == 'r' ? 0 : 1), dp[i - 1][2] + (leaves[i] == 'r' ? 0 : 1));
            }
        }
        return dp[leaves_size - 1][2];
    }
};