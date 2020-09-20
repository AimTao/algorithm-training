#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int space_num = 0, word_num = 0;

        int i = 0;
        while (i < text.size()) {
            if (text[i] != ' ') {
                word_num++;
                while (i < text.size() && text[i] != ' ') {
                    i++;
                }
            }
            if (i < text.size() && text[i] == ' ') {
                while (i < text.size() && text[i] == ' ') {
                    space_num++;
                    i++;
                }
            }
        }
        int once = 0;
        int last_once = space_num;
        if (word_num != 1) {
            once = space_num / (word_num - 1);
            last_once = space_num % (word_num - 1);
        }
        string ans = "";
        i = 0;
        while (i < text.size()) {
            if (text[i] != ' ') {
                while (i < text.size() && text[i] != ' ') {
                    ans += text[i];
                    i++;
                }
                if (i < text.size() && ans.size() + last_once != text.size()) {
                    for (int j = 0; j < once; j++) {
                        ans += ' ';
                    }
                }
            }
            if (i < text.size() && text[i] == ' ') {
                while (i < text.size() && text[i] == ' ') {
                    i++;
                }
            }
        }
        for (int j = 0; j < last_once; j++) {
            ans += ' ';
        }
        return ans;
    }
};