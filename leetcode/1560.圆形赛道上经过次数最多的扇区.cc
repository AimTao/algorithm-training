#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        map<int, int> m;
        int size = rounds.size();
        for (int i = 0; i < size - 1; i++) {
            if (rounds[i] > rounds[i+1]) {
                for (int j = rounds[0]; j <= n; j++) {
                    m[j] = 1;
                }
                break;
            }
        }

        for (int i = size - 1; i > 0; i--) {
            if (rounds[i] < rounds[i - 1]) {
                for (int j = 1; j <= rounds[size - 1]; j++) {
                    if (m[j] == 0) {
                        m[j] = 1;
                    } else {
                        m[j]++;
                    }
                }
                break;
            }
        }
        vector<int> ans;
        if (m.size() != 0) {
            int max = 0;
            for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
                if (it->second > max) {
                    max = it->second;
                }
            }
            
            for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
                if (it->second == max) {
                    ans.push_back(it->first);
                }
            }
        } else {
            for (int i = rounds[0]; i <= rounds[size - 1]; i++) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};