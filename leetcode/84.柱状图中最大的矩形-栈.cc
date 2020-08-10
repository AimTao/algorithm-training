#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> new_heights(n + 2, 0);
    for (int i = 0 ; i < n; i++) {
        new_heights[i + 1] = heights[i];
    }
    n += 2;
    stack<int> s;
    s.push(0);
    int max_area = 0;
    int area = 0;
    for (int i = 0; i < n; i++) {
        while (new_heights[i] < new_heights[s.top()]) {
            int tmp = s.top();
            s.pop();
            area = (i - s.top() - 1) * heights[tmp];
            max_area = max(max_area, area);
        }
        s.push(i);
    }
    return max_area;
}