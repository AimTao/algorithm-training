/*
走楼梯问题
*/
#include <iostream>
#include <vector>
using namespace std;

long long fun(int n, vector<long long> &num){
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (num[n] == -1) {
        num[n] = fun(n - 1, num) + fun(n - 2, num);
    }
    return num[n];
}

int main(){
    int n = 10;
    vector<long long> num(n+1, -1);
    cout << fun(n, num) << endl;
    return 0;
}