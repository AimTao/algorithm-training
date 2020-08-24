#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        string s = "";
        if (n == 0) {
            s += '0';
            return s;
        }
        int tmp = 0;
        while (n) {
            tmp++;
            int num = n % 10;
            s += num + '0';
            n /= 10;
            if (tmp == 3 && n) {
                tmp = 0;
                s += '.';
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};