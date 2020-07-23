#include <iostream>
#include <vector>
using namespace std;

int MinNum(vector<vector<int> >& triangle, int i, int j, vector<vector<int> > &memo){
    if (i == 0) {
        memo[i][0] = triangle[i][0];
        
    }
    if (memo[i][j] == 0x3f3f3f3f && j > 0 && j < i) {
        memo[i][j] = min(MinNum(triangle, i - 1, j - 1, memo), 
            MinNum(triangle, i - 1, j, memo)) + triangle[i][j];
            
    }
    if (memo[i][j] == 0x3f3f3f3f && j == 0) {
        memo[i][j] = MinNum(triangle, i - 1, j, memo) + triangle[i][j];
    }
    if (memo[i][j] == 0x3f3f3f3f && j == i) {
        memo[i][j] = MinNum(triangle, i - 1, j - 1, memo) + triangle[i][j];
    }
    return memo[i][j];
}

int minimumTotal(vector<vector<int> >& triangle){
    int size = triangle.size();
    vector<vector<int> > memo(size, vector<int>(size, 0x3f3f3f3f));
    vector<int> min_num;
    for (int i = 0; i < size; i++) {
        min_num.push_back(MinNum(triangle, triangle.size()-1, i, memo));
        
    }
    int min_ans = min_num[0];
    for (int i = 1; i < min_num.size(); i++) {
        if (min_num[i] < min_ans) {
            min_ans = min_num[i];
        }
    }
    return min_ans;
}

int main(){
    int source_0[] = {2};
    int source_1[] = {3,4};
    int source_2[] = {6,5,7};
    int source_3[] = {4,1,8,3};
    vector<vector<int> > triangle(4);
    triangle[0].insert(triangle[0].begin(), source_0, source_0 + 1);
    triangle[1].insert(triangle[1].begin(), source_1, source_1 + 2);
    triangle[2].insert(triangle[2].begin(), source_2, source_2 + 3);
    triangle[3].insert(triangle[3].begin(), source_3, source_3 + 4);
    cout << minimumTotal(triangle);
    return 0;
}