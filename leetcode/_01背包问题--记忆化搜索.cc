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
记忆化搜索的方法，为了解决递归方法中的重叠子问题。
重叠子问题：用 [0...index] 的物品，填充容积为c的背包的最大价值。
（index，c）的数据对，我们可能多次重复计算。
*/
vector<vector<int> > memo;
// 用 [0...index] 的物品，填充容积为c的背包的最大价值。
int best_value(const vector<int> &w, const vector<int> &v, int index, int c) {
    if (index < 0 || c <= 0) {
        return 0;
    }
    
    // 当该组数据被计算过，就直接放回数据。
    if (memo[index][c] != -1) {
        return memo[index][c];
    }

    int res = best_value(w, v, index - 1, c);
    if (w[index] <= c) {
        
        res = max(res, best_value(w, v, index - 1, c - w[index]) + v[index] );
    }
    memo[index][c] = res;
    return res;
}

int Knapsack(const vector<int> &w, const vector<int> &v, int c) {
    int n = w.size();
    memo = vector<vector<int> >(n, vector<int>(c + 1, -1));
    return best_value(w, v, n - 1, c);
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