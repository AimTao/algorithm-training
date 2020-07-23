#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<int> memo(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[i][j] == 1) {
                memo[j] = 0;
                if (i == 0) {
                    break;
                }
                continue;
            }
            if (i == 0) {
                memo[j] = 1;
            } else if (j == 0) {
                memo[j] = memo[j];
            } else { 
                memo[j] = memo[j] + memo[j - 1];
            }
        }
    }
    return memo[m - 1];
}
