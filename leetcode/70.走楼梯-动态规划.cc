/*
走楼梯问题
*/
#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int a = 2, b = 1, c = 0;
    for (int i = 3; i <= n; i++){
        c = a + b;
        b = a;
        a = c;
    }
    cout << c << endl;
    return 0;
}