#include <iostream>
using namespace std;
int main() {
    const int N = 1000001;
    int f[N] = {0};
    f[1] = f[2] = 1;
    int n;
    cin >> n;
    for (int i=3; i<n+1; i++) {
        f[i] = (f[i-1] + f[i-2]) % 10007;
    }
    cout << f[n];
    return 0;
}