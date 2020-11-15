#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string& MyInvert(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            s[i] = '0';
        } else {
            s[i] = '1';
        }
    }
    return s;
}

char findKthBit(int n, int k) {
    vector<string> s(21, "");
    s[1] = "0";
    //Si = Si-1 + "1" + reverse(invert(Si-1))
    for (int i = 2; i <= n; i++) {
        s[i] = s[i - 1] + "1";
        MyInvert(s[i - 1]);
        reverse(s[i - 1].begin(), s[i - 1].end());
        s[i] = s[i] + s[i - 1];

    }
    return s[n][k - 1];
}