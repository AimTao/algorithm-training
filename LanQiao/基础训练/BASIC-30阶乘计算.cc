#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    a[0] = 1; 
    vector<int> flag;
    flag.push_back(0);
    for (int i = 1; i <= n; i++) {
        flag[0] = 0;
        for (int j = 1; j < flag.size(); j++) {
            flag[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            if (i * a[j] > 10){
                flag.push_back(i * a[j] / 10);
                a[j] = i * a[j] % 10;
            } else {
                a[j] = i * a[j];
            } 
        }
        for (int j = 0; j < n; j++) {
            a[j] += flag[j];
            if (a[j] > 10) {
                a[j + 1]++;
                a[j] -= 10;
            }
        }
    }
}