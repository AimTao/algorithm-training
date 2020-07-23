#include <iostream>
using namespace std;

int num = 0;
void dfs(string s, int index, int n){
    if (index == n) {
        num++;
        return;
    }
    if (s[index + 1] != '0') {
        dfs(s, index + 1, n);
        if (index + 2 <= n && (s[index + 1] - '0') < 3 
            && (s[index + 1] - '0') * 10 + (s[index + 2] - '0') <= 26) {
            dfs(s, index + 2, n);
        }
    }
    return;
}

int numDecodings(string s) {
    int n = s.length() - 1;
    dfs(s, -1, n);
    return num;
}


int main(){
    cout << numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948");
}