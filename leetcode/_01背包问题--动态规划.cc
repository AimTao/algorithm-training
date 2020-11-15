/*
问题描述：
有一个背包，容量为 c 【Capacity】,
现在有 n 种不同的物品，编号为 0...n-1,
其中每一件物品重量为 w(i), 价值为 v(i),
问可以向这个背包放入哪些物品，使得不超过容量的基础上，物品的总值最大？
*/
#include <iostream>
#include <vector>
using namespace std;

/*
将自顶向下的记忆化搜索 转变为 自底向上的动态规划
用 [0...index] 的物品，填充容积为c的背包的最大价值。
*/
vector<vector<int> > memo;

int Best(const vector<int> &w, const vector<int> &v, int c) {
    int n = w.size();
    if (n == 0) {
        return 0;
    }
    for (int i = 0; i <= c; i++) {
        memo[0][i] = (w[0] <= i ? v[0] : 0);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= c; j++) {
            int res = memo[i - 1][j];
            if (j >= w[i]) {
                res = max(res, memo[i - 1][j - w[i]] + v[i]);
            }
            memo[i][j] = res;
        }
    }
    return memo[n - 1][c];
}

int Knapsack(const vector<int> &w, const vector<int> &v, int c) {
    int n = w.size();
    memo = vector<vector<int> >(n, vector<int>(c + 1, -1));
    return Best(w, v, c);
}

// 测试程序
int main() {
    int a[] = {1, 2, 3};
    int b[] = {6, 10, 12};
    vector<int> w = vector<int>(a, a + sizeof(a) / sizeof(int));
    vector<int> v = vector<int>(b, b + sizeof(b) / sizeof(int));
    int c = 5;
    cout << Knapsack(w, v, c);
}