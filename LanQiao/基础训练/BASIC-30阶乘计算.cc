// 思路分析见 https://www.aimtao.net/categories/Mark/Lan-Qiao/

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
        for (int j = 0; j < ans.size(); j++) {
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
易错：
29-36行，对ans的最高位进位的操作必不可少，否则下一轮，最高位的乘法的结果会爆
i-- 别写成 i++
*/