#include <iostream>
#include <map>
using namespace std;
int main() {
    string a[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", 
        "1010", "1011", "1100", "1101", "1110", "1111"};
    map<string, string> m;
    m["000"] = "0";
    m["001"] = "1";
    m["010"] = "2";
    m["011"] = "3";
    m["100"] = "4";
    m["101"] = "5";
    m["110"] = "6";
    m["111"] = "7";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s16 = "", s2 = "", s8 = "";
        cin >> s16;
        for (int j = 0; j < s16.size(); j++) {
            if (s16[j] > '9') {
                s2 += a[s16[j] - 'A' + 10];
            } else {
                s2 += a[s16[j] - '0'];
            }
        }
        if (s2.size() % 3 == 1) {
            s2 = "00" + s2;
        } else if (s2.size() % 3 == 2) {
            s2 = "0" + s2;
        }
        int flag = 0;
        for (int j = 0; j < s2.size(); j += 3) {
            string tmp = s2.substr(j, 3);
            s8 += m[tmp];    
            if (j == 0 && m[tmp] == "0") {
                flag = 1;
            }
        }
        if (flag) {
            s8 = s8.substr(1);
        }
        cout << s8;
        cout << endl;
    }
    return 0;
}

/*
易错：
1. 第5行，初始化数组，逗号少写。
2. 第22行，s16[j] > '9'，9的单引号，别少写
3. 第29行，不能写成 s2 += “00”，因为 “00” 应该在前面
4. 第45行，注意换行，保持格式一致
*/