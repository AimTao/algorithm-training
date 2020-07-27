#include <iostream>
#include <vector>
#include <string>

using namespace std;

string restoreString(string s, vector<int>& indices) {
    int n = indices.size();
    char tmp[102] = {0};
    string ans = "";
    for (int i = 0; i < n; i++) {
        tmp[indices[i]] = s[i];
    }
    for (int i = 0; i < n; i++) {
        ans = ans + tmp[i];
    }
    return ans;
}