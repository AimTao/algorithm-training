#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minFlips(string target) {
    int memo, key;
    int n = target.size();
    if (target[n - 1] == '0') {
        key = 0;
        memo = 0;
    } else {
        key = 1;
        memo = 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (target[i] == '0') {
            key = 0;
        } else if (key == 0) {
            key = 1;
            memo += 2;
        } else if (key == 1) {
            key = 1;
        }
        
    }
    return memo;
}