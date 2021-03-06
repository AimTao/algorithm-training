#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector< vector<int> >& points) {
        int first = 0;
        int ans_x = 0, ans_y = 0;
        int ans = 0;
        int ans_i = 0;
        int size = points.size();
        for (int i = 0; i < size; i++) {
            if (points[i][0] == x || points[i][1] == y) {
                if (first == 0) {
                    ans = abs(points[i][0] - x) + abs(points[i][1] - y);
                    ans_x = points[i][0];
                    ans_y = points[i][1];
                    ans_i = i;
                    first = 1;
                } else {
                    int new_ans = abs(points[i][0] - x) + abs(points[i][1] - y);
                    if (new_ans < ans) {
                        ans = new_ans;
                        ans_x = points[i][0];
                        ans_y = points[i][1];
                        ans_i = i;
                    } else if (new_ans == ans) {
                        if ((points[i][0] + points[i][1]) < ans_x + ans_y) {
                            ans_x = points[i][0];
                            ans_y = points[i][1];
                            ans_i = i;
                        }
                    }
                }
            }
        }
        if (first == 0) {
            return -1;
        }
        cout << "ans_x = " << ans_x << endl;
        cout << "ans_y = " << ans_y << endl;
        return ans_i;
    }
};