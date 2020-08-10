#include <iostream>
#include <vector>
#include <string>
#include<cstring>
using namespace std;

vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            for (int k = 1; k < 4; k++) {
                for (int l = 1; l < 4; l++) {
                    if (i + j + k + l == s.size()) {
                        int a = stoi(s.substr(0, i));
                        if ((i == 2 && a < 10) || (i == 3 && a < 100)) {
                            break;
                        }
                        int b = stoi(s.substr(i, j));
                        if ((j == 2 && b < 10) || (j == 3 && b < 100)) {
                            break;
                        }
                        int c = stoi(s.substr(i + j, k));
                        if ((k == 2 && c < 10) || (k == 3 && c < 100)) {
                            break;
                        }
                        int d = stoi(s.substr(i + j + k));
                        if ((l == 2 && d < 10) || (l == 3 && d < 100)) {
                            break;
                        }
                        if (a <= 255 && b <= 255 && c <= 255 && d <= 255) {
                            string tmp = s.substr(0, i);
                            tmp += '.';
                            tmp += s.substr(0 + i, j);
                            tmp += '.';
                            tmp += s.substr(0 + i + j, k);
                            tmp += '.';
                            tmp += s.substr(0 + i + j + k);
                            ans.push_back(tmp);
                        }
                    }
                }
            }
        }
    }  
    return ans;      
}