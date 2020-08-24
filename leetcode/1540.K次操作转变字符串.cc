#include <iostream>
#include <vector>
using namespace std;

bool canConvertString(string s, string t, int k) {
    int n1 = s.size(), n2 = t.size();
    if (n1 != n2) {
        return false;
    }
    int ans[27] = {0};
    for (int i = 0; i < n1; i++) {
        int tmp = t[i] - s[i];
        if (tmp < 0) {
            tmp = tmp + 26;
        }
        ans[tmp]++;
    }
    int ans_count = 0;
    for (int i = 1; i < 27; i++) {
        if (ans[i]) {
            int tmp = i + (ans[i] - 1) * 26;
            ans_count = max(tmp, ans_count);
        } 
    }
    if (ans_count >= k) {
        return true;
    } else {
        return false;
    }
}