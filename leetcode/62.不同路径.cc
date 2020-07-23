#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int> > memo(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                memo[i][j] = 1;
            } else {
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
            }
        }
    }
    return memo[n - 1][m - 1];
}

int main(){
    cout << uniquePaths(3, 2);
}