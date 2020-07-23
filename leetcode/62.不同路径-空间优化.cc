#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int> memo(m, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                memo[j] = 1;
            } else {
                memo[j] = memo[j] + memo[j - 1];
            }
        }
    }
    return memo[m - 1];
}

int main(){
    cout << uniquePaths(3, 2);
}