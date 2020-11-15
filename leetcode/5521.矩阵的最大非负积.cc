#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int> >& grid) {
        int row = grid.size(), col = grid[0].size();
        if (!grid[0][0] || !grid[row - 1][col - 1]) {
            return 0;
        }
        vector<int> max_ans(col, 0), min_ans(col, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!j && !i) {
                    max_ans[j] = grid[i][j];
                    min_ans[j] = grid[i][j];
                    continue;
                }
                if (i == 0) {
                    max_ans[j] = max(grid[i][j] * max_ans[j - 1], grid[i][j] * min_ans[j - 1]);
                    min_ans[j] = min(grid[i][j] * max_ans[j - 1], grid[i][j] * min_ans[j - 1]);
                    continue;
                }
                if (j == 0) {
                    max_ans[j] = max(grid[i][j] * max_ans[j], grid[i][j] * min_ans[j]);
                    min_ans[j] = min(grid[i][j] * max_ans[j], grid[i][j] * min_ans[j]);
                    continue;
                }
                max_ans[j] = max(max(grid[i][j] * max_ans[j - 1], grid[i][j] * min_ans[j - 1]), max(grid[i][j] * max_ans[j], grid[i][j] * min_ans[j]));
                min_ans[j] = min(min(grid[i][j] * max_ans[j - 1], grid[i][j] * min_ans[j - 1]), min(grid[i][j] * max_ans[j], grid[i][j] * min_ans[j]));
            }
            for (int i = 0; i < col; i++) {
                cout << max_ans[i] << " " << min_ans[i] << "          ";
            }
            cout << endl;
        }
        if (max_ans[col - 1] < 0) {
            return -1;
        }
        
        return max_ans[col - 1];
    }
};

int main() {
    int arr[][3] = {{-1,-2,-3},{-2,-3,-3},{-3,-3,-2}};
    vector<vector<int> > a(sizeof(arr) / sizeof(arr[0]), vector<int>(sizeof(arr[0]) / sizeof(arr[0][0]), 0));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        a[i].assign(arr[i], arr[i] + sizeof(arr[i]) / sizeof(arr[i][0]));
    }
    // cout << Solution().maxProductPath(a);
    Solution().maxProductPath(a);
}