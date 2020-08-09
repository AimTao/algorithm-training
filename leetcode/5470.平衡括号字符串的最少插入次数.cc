#include <iostream>
#include <string>
#include <stack>
using namespace std;

int minInsertions(string s) {
    stack<char> m;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')' && m.empty()) {
            if (i + 1 < n  && s[i + 1] == ')') {
                ans++;
                i++;
                continue;
            } else {
                ans += 2;
                continue;
            }    
        }
        if (s[i] == '(') {
            m.push(s[i]);
            continue;
        }
        if (s[i] == ')') {
            if (i + 1 < n && s[i + 1] == ')') {
                m.pop();
                i++;
                continue;
            } else {
                m.pop();
                ans++;
                continue;
            }
        }
    }
    int nums = m.size();
    ans += nums * 2;
    return ans;
}