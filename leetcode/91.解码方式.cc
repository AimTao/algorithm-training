#include <iostream>
#include <vector>
using namespace std;

int numDecodings(string s) {
    if (s[0] == '0') {
        return 0;
    }
    s = '0' + s;
    int n = s.length();
    vector<int> memo(n, 0);
    memo[0] = 1;
    memo[1] = 1;
    for (int i = 2; i < n; i++) {
        if (s[i] != '0') {
            memo[i] += memo[i - 1];
        }
        if (s[i - 1] != '0' && s[i - 1] - '0' < 3) {
            if (s[i - 1] - '0' < 2 || s[i] - '0' < 7) {
                memo[i] += memo[i - 2];
            }
        }
    }
    return memo[n - 1];
}


int main(){
    cout << numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948");
}