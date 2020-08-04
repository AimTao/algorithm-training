#include <iostream>
#include <string>
using namespace std;

string addStrings(string num1, string num2) {
    int n1 = num1.size(), n2 = num2.size();
    int i = n1 - 1, j = n2 - 1, add = 0;
    string ans;
    while (i >= 0 || j >= 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        ans.push_back((x + y + add) % 10 + '0');
        add = (x + y + add) / 10;
        i--;
        j--;
    }
    while (add) {
        ans.push_back(add % 10 + '0');
        add /= 10;
    }
    reverse(ans.begin, ans.end);
    return ans;
}