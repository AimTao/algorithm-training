#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int numSquares(int n) {
    vector<int> min_num(n + 1, 0x7fffffff);
    min_num[0] = 0;
    min_num[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; i - j * j >= 0; j++) {
            min_num[i] = min(min_num[i - j * j] + 1, min_num[i]);
        }
    }
    return min_num[n];
}

int main() {
    cout << numSquares(4) << endl;
}