#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int size = s.size();
        int flag = 1;
        for (int i = 0; i < size; i++) {
            if (flag && s[i] == '1') {
                continue;
            } else if (flag && s[i] == '0') {
                flag = 0;
            } else if (!flag && s[i] == '1') {
                return false;
            }
        }
        return true;
    }
};
