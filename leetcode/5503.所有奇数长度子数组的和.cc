#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for (int j = 0; j < n; j++) {
            for (int i = 1; i <= n; i += 2) {
                if (j + i <= n) {
                    for (int k = 0; k < i; k++) {
                        ans += arr[j+k];
                    }
                }
            }
        }
    return ans;
    }
};