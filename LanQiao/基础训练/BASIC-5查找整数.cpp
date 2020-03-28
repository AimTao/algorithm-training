#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            cout << i + 1;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << "-1";
    }
    return 0;
}
/*
易错：
计数需要 i + 1
*/