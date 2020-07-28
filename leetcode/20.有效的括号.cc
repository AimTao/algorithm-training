#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> tmp;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            tmp.push(s[i]);
        } else {
            if (s[i] == ')' && !tmp.empty() && tmp.top() == '(') {
                tmp.pop();
            } else if (s[i] == ']' && !tmp.empty() && tmp.top() == '[') {
                tmp.pop();
            } else if (s[i] == '}' && !tmp.empty() && tmp.top() == '{') {
                tmp.pop();
            } else {
                 return false;
            }
        }
    }
    if (!tmp.empty()) {
        return false;
    }
    return true; 
}