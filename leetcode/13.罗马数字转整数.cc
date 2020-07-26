#include <iostream>
#include <string>
using namespace std;

int romanToInt(string s) {
    int n = s.size();
    int num = 0;
    int m[100] = {0};
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    for (int i = 0; i < n; i++) {
        m[s[i]] >= m[s[i + 1]] ? num += m[s[i]] : num -= m[s[i]];
    }

    return num;
}