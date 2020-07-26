#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    if (x == 0) {
        return true;
    }
    stringstream ss;
    string s;
    ss << x;
    ss >> s;
    int n = s.size();
    for (int i = 0; i < n; i ++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}