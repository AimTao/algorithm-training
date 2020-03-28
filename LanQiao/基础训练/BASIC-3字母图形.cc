#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                a[i][j] = 'A';
            } else if (i < j) {
                a[i][j] = 'A' + j - i;
            } else if (i > j) {
                a[i][j] = 'A' + i - j;
            }
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}