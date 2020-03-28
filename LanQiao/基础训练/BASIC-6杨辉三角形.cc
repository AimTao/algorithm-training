#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) {
                a[i][j] = 1;
            } else {
                a[i][j] = a[i-1][j] + a[i-1][j-1]; 
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
易错：
注意边界问题，第八行
*/