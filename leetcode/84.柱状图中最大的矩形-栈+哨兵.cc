#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int n = heights.size();
    int max_area = 0;
    int area = 0;
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int tmp = s.top();
            s.pop();
            if (s.empty()) {
                area = i * heights[tmp];
            } else {
                area = (i - s.top() - 1) * heights[tmp];
            }
            max_area = max(max_area, area);
        }
        s.push(i);
    }
    int left = 0;
    if (!s.empty()) {
        // left = s.top() + 1;  // 也可以写成这样。
        left = n;   // 左边的边界一定是 最右边元素的索引 + 1。
    }
    while (!s.empty()) {
        int tmp = s.top();
        s.pop();
        if (s.empty()) {
            area = left * heights[tmp];
        } else {
            area = (left - s.top() - 1) * heights[tmp];
        }
        max_area = max(max_area, area);
    }
    return max_area;
}