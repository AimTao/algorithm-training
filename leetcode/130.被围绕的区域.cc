#include <iostream>
#include <vector>
using namespace std;

/*
关键点：
    - 与边界 O 相接连的 O 不变
    - 没有与边界 O 相接连的 O 变成 X

步骤：
    1. 先挑出所有与边界 O 相连的 O，标记为 T；
        - 从边界 O 出发；
        - 上下左右搜索 O 点；
        - 标记为 T；
    2. 将所有 O 变为 X，所有 T 变为 O；

*/

int n, m;

void Dfs(vector<vector<char> >& board, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }
    if (board[x][y] == 'O') {
        board[x][y] = 'T';
        Dfs(board, x + 1, y);
        Dfs(board, x - 1, y);
        Dfs(board, x, y + 1);
        Dfs(board, x, y - 1);
    }
    return;
}

void solve(vector<vector<char> >& board) {
    n = board.size();
    if (!n) {      // 注意点 1.防止 m = board[0].size() 越界，先判断是否为空。
        return;
    }
    m = board[0].size();

    // 先遍历 左边界&右边界 的 O 点
    for (int i = 0; i < n; i++) {
        Dfs(board, i, 0);
        Dfs(board, i, m - 1);
    }

    // 先遍历 上边界&下边界 的 O 点
    for (int i = 0; i < m; i++) {
        Dfs(board, 0, i);
        Dfs(board, n - 1, i);
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'T') {
                board[i][j] = 'O';
            }
        }
    }
    return;
}