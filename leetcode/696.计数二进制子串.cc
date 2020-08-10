#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countBinarySubstrings(string s) {
    int n = s.size();
    if (n <= 1) {
        return 0;
    }
    vector<int> count;
    int tmp_count = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            tmp_count++;
        } else {
            count.push_back(tmp_count);
            tmp_count = 1;
        }
    }
    count.push_back(tmp_count);
    int ans = 0;
    for (int i = 1; i < count.size(); i++) {
        ans += min(count[i - 1], count[i]);
    }
    return ans;
}