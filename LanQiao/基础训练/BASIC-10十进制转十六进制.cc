#include <iostream>
#include <sstream>
using namespace std;
int main() {
    long long s10;
    cin >> s10;
    stringstream ss;
    ss << hex << s10;
    string s16;
    ss >> s16;
    for (int i = 0; i < s16.size(); i++) {
        if (s16[i] > '9') {
            s16[i] = s16[i] - 32;
        }
        cout << s16[i];
    }
    return 0;
}