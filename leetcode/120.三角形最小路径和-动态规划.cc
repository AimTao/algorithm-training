#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int> >& triangle) {
      if(triangle.size() == 1)
        return triangle[0][0];

      int size = triangle[triangle.size() - 1].size();
      vector<int> dp(size, 0);
      dp[0] = triangle[0][0];
      int res = INT_MAX;

      for(int i = 1; i < triangle.size(); i++){
        for(int j = triangle[i].size() - 1; j >= 0; j--){
          if(j == triangle[i].size() - 1){
            dp[j] = dp[j - 1] + triangle[i][j];
          }else if(j == 0){
            dp[j] = dp[j] + triangle[i][j];
          }else{
            dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
          }
        }
      }

      for(int i = 0; i < dp.size(); i++){
        res = min(res, dp[i]);
      }

      return res;
}