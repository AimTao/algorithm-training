#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        map<int, int> m;
        for (int i = 0 ; i < n; i++) {
            m[i] = 0;
        }
        int x = edges.size();
        for (int i = 0; i < x; i++) {
            m[edges[i][1]] = 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!m[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};