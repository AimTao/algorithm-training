#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    int key = 0;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = key; j < m; j++) {
            if (s[i] == t[j]) {
                key = j + 1;
                tmp = 1;
                break;
            }
        }
        if (tmp == 0) {
            return false;
        } else {
            tmp = 0;
        }
    }
    return true;
}