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

// 用 [0...index] 的物品，填充容积为c的背包的最大价值。
int best_value(const vector<int> &w, const vector<int> &v, int index, int c) {
    
    // cout << "  (" << index << "," << c << ")  " << endl;
    if (index < 0 || c <= 0) {
        return 0;
    }
    int res = best_value(w, v, index - 1, c);
    if (w[index] <= c) {
        res = max(res, best_value(w, v, index - 1, c - w[index]) + v[index] );
    }
    return res;
}

int Knapsack(const vector<int> &w, const vector<int> &v, int c) {
    int n = w.size();
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