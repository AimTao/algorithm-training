#include <iostream>
#include <vector>
using namespace std;

int DP(vector<int> &cost, int i, vector<int> &memo){
    if (i == 0 || i == 1) {
        memo[i] = cost[i];
    }
    if (memo[i] == -1) {
        memo[i] = min(DP(cost, i - 1, memo), DP(cost, i - 2, memo)) + cost[i];
        cout << i << " = " << memo[i] << endl;
    }
    return memo[i];
}

int minCostClimbingStairs(vector<int> &cost) {
    cost.push_back(0);
    int size = cost.size();
    vector<int> memo(size, -1);
    return DP(cost, size - 1, memo);
}

int main(){
    vector<int> a;
    a.push_back(10);
    a.push_back(15);
    a.push_back(20);
    cout << minCostClimbingStairs(a) << endl;
    return 0;
}