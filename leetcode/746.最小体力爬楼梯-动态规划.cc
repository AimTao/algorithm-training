#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int> &cost) {
    cost.push_back(0);
    int dp_1 = cost[0], dp_2 = cost[1], dp_3 = 0;
    for (int i = 2; i < cost.size(); i++) {
        dp_3 = min(dp_1, dp_2) + cost[i];
        dp_1 = dp_2;
        dp_2 = dp_3;
    }
    return dp_3;
}

int main(){
    vector<int> a;
    a.push_back(10);
    a.push_back(15);
    a.push_back(20);
    cout << minCostClimbingStairs(a) << endl;
    return 0;
}