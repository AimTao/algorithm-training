#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;
int MaxBreak(int n){
    if (n == 1) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    for (int i = 1; i <= n; i++) {
        memo[n] = max(max(MaxBreak(n - i) * i, (n - i) * i), memo[n]);
    }
    return memo[n];
}

int integerBreak(int n) {
    memo = vector<int>(n + 1, -1);
    return MaxBreak(n);
}

int main(){
    int n = 10;
    cout << integerBreak(n);
    return 0;
}