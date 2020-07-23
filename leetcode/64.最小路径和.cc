#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int size = grid.size();
        if (size == 0) {
            return 0;
        }
        int row = grid[0].size();
        vector<vector<int> > memo(size, vector<int>(row, 0x3f3f3f3f));      
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < row; j++) {
                if (i == 0 && j == 0) {
                    memo[i][j] = grid[0][0];
                } else if (j == 0) {
                    memo[i][j] = memo[i - 1][j] + grid[i][j];
                } else if (i == 0) {
                    memo[i][j] = memo[i][j - 1] + grid[i][j];
                } else {
                    memo[i][j] = min(memo[i][j - 1], memo[i - 1][j]) + grid[i][j];
                }    
            }
        }
        return memo[size - 1][row - 1];
    }
};

int main(){

}