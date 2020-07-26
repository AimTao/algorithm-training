#include <iostream>
#include <vector>
using namespace std;

bool divisorGame(int N) {
    vector<bool> memo(N + 1, false);
    for (int i = 2; i <= N; i++) {
        if (!memo[i - 1]) {
            memo[i] = true;
        }
    }
    return memo[N];
}