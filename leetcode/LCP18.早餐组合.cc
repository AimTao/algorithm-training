#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        long long s_size = staple.size(), d_size = drinks.size();
        long long ans = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());

        // 双指针计数
        long long i = 0, j = d_size - 1;
        while (i < s_size && j >= 0) {
            if (staple[i] + drinks[j] > x) {
                j--;
                continue;
            } else {
                ans += j + 1;
                i++;
                continue;
            }
        }
        return ans  % 1000000007;
    }
};