#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        string ans = "";
        for (int i = 0; i < size; i++) {
            int start = i;
            while (i < size && s[i] != ' ') {
                i++;
            }
            for (int j = i - 1; j >= start; j--) {
                ans.push_back(s[j]);
            }
            while (i < size && s[i] == ' ') {
                ans += ' ';
                i++;
            }
        }
        return ans;
    }
};