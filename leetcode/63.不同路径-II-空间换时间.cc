#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int> > memo(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[0][i] == 0) {
            memo[0][i] = 1;
        } else {
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        if (obstacleGrid[i][0] == 0) {
            memo[i][0] = 1;
        } else {
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (obstacleGrid[i][j] == 0) {
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
            }
        }   
    }
    return memo[n - 1][m - 1];
}
