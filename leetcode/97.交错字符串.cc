#include <iostream>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size()) {
        return false;
    }
    vector<vector<bool> > memo(n + 1, vector<bool>(m + 1, false));
    memo[0][0] = true;
    for (int i = 1; i <= m; i++) {
        memo[0][i] = memo[0][i - 1] && (s1[i - 1] == s3[i - 1]);
        if (!memo[0][i]) {
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        memo[i][0] = memo[i - 1][0] && (s2[i - 1] == s3[i - 1]);
        if (!memo[i][0]) {
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            memo[i][j] = (memo[i - 1][j] && (s2[i - 1] == s3[i + j - 1])) || 
                            (memo[i][j - 1] && (s1[j - 1] == s3[i + j - 1]));
        }
    }
    return memo[n][m];
}