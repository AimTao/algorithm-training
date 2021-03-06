#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> memo(n+2, 0);
        memo[0] = 0;
        int num = 1;
        while (num < n) {
            memo[num] = 1;
            num *= 3;
        }
        for (int i = 3; i <= n; i *= 3) {
            for (int j = 1; j < i; j++) {
                if (i + j <= n && memo[j] == 1) {
                    memo[i + j] = 1;
                }
            }
        }
        return memo[n];
    }
};