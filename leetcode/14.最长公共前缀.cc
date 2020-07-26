#include <iostream>
#include <string>
#include <vector>
using namespace std;

string CommonPrefix(string &a, string &b) {
    int length_a = a.size();
    int length_b = b.size();
    int length_min = min(length_a, length_b);
    string ans = "";
    for (int i = 0; i < length_min; i++) {
        if (a[i] != b[i]) {
            break;
        }
        ans = ans + a[i];
    }
    return ans;
}

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if (n == 0) {
        return ""; 
    }
    if (n == 1) {
        return strs[0];
    }
    for (int i = 0; i < n - 1; i ++) {
        strs[i + 1] = CommonPrefix(strs[i], strs[i + 1]);
    }
    return strs[n - 1];
}