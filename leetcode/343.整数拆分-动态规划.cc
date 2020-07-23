#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n) {
    vector<int> memo(n + 1, -1);
    memo[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            memo[i] = max(max(memo[i - j], i - j) * j, memo[i]);
        }
    }
    return memo[n];
}

int main(){
    int n = 10;
    cout << integerBreak(n);
    return 0;
}