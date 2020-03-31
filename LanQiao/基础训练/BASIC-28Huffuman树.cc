#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    int sum = 0;
    while (a.size() != 1) {
        sum += a[0] + a[1];
        a[1] += a[0];
        a.erase(a.begin());
        sort(a.begin(), a.end());
    }
    cout << sum;
    return 0;
}