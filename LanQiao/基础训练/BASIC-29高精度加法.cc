#include <iostream>
using namespace std;
int main() {
    const int n = 1000;
    int a[n] = {0};
    int b[n] = {0};
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        a[i] = s1[s1.size() - 1 - i] - '0';
    }
    for (int i = 0; i < s2.size(); i++) {
        b[i] = s2[s2.size() - 1 - i] - '0';
    }
    for (int i = 0; i < n; i++) {
            a[i + 1] += (a[i] + b[i]) / 10;
            a[i] = (a[i] + b[i]) % 10;
    }
    int tmp = 1;
    for (int i = n - 1; i >= 0; i--) {
         if (a[i]) {
            tmp = i;
            break;
        }
    }
    for (int i = tmp; i >= 0; i--) {
        cout << a[i];
    }
    return 0;
}