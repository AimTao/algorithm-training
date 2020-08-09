#include <iostream>
#include <string>
using namespace std;

string makeGood(string s) {
    int k = 1;
    while(k) {
        k = 0;
        if (s.size() == 0) {
            return s;
        }
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] - s[i + 1] == 32 || s[i + 1] - s[i] == 32) {
                s.erase(i, 2);
                k = 1;
                break;
            }
        }
    }
    return s;
}