#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ans, flag;
    ans.push_back(1);
    flag.push_back(0);
    for (int i = 2; i <= n; i++) {
        int lens = ans.size();
        for (int j = 0; j < lens; j++) {
            ans[j] = i * ans[j] + flag[j];
            flag[j] = 0;
            if (ans[j] >= 10) {
                if (flag.size() - 1 == j) {
                    flag.push_back(ans[j] / 10);
                } else {
                    flag[j + 1] = ans[j] / 10;
                }
                ans[j] %= 10;
            } else {
                if (flag.size() - 1 == j) {
                    flag.push_back(0);
                } else {
                    flag[j + 1] = 0;
                }
            }
        }
        while (flag[flag.size() - 1]) {
            ans.push_back(flag[flag.size() - 1]);
            if (ans[ans.size() - 1] >= 10) {
                flag.push_back(ans[ans.size() - 1] / 10);
                ans[ans.size() - 1] %= 10;
            } else {
                flag.push_back(0);
            }
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;
}
/*
用 ans 表示 每一位的数值
用 flag 表示 每次进位的数值
*/