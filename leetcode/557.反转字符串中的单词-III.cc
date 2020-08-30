#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        string ans = "", tmp = "";
        for (int i = 0; i < size; i++) {
            if (s[i] == ' ') {
                reverse(tmp.begin(), tmp.end());
                ans += tmp;
                ans += s[i];
                tmp = "";
            } else if (i == size - 1) {
                tmp += s[i];
                reverse(tmp.begin(), tmp.end());
                ans += tmp;
            } else {
                tmp += s[i];
            }
        }
        return ans;
    }
};