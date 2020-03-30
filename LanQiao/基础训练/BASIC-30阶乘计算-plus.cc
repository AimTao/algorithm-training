#include <iostream>
using namespace std;
int main() {
    int a[10000] = {1};
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10000; j++) {
            a[j] *= i;
        }
        for (int j = 0; j < 10000; j++) {
            if (a[j] >= 10) {
                a[j + 1] += (a[j] / 10);
                a[j] %= 10; 
            }
        }
    }
    int flag = 0;
    for (int i = 9999; i >= 0; i--) {
        if (a[i] == 0) {
            continue;
        }
        flag = i;
        break;
    }
    for(int i = flag; i >= 0; i--) {
        cout << a[i];
    }
    return 0;
}