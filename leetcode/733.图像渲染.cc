#include <iostream>
#include <vector>
using namespace std;

int n = 0, m = 0;
int source_color = 0;
int aim_color = 0;

void Dfs(vector<vector<int> >& image, int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m || image[x][y] != source_color) {
        return;
    }
    image[x][y] = aim_color;
    Dfs(image, x + 1, y);
    Dfs(image, x - 1, y);
    Dfs(image, x, y + 1);
    Dfs(image, x, y - 1);
    return;
}

vector<vector<int>> floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
    if (image[sr][sc] == newColor) {   // 如果不判断，会陷入互找死循环
        return image;
    }
    n = image.size();
    m = image[0].size();
    source_color = image[sr][sc];
    aim_color = newColor;
    Dfs(image, sr, sc);
    return image;
}