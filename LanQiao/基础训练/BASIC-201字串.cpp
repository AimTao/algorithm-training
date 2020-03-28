#include <iostream>
#include <bitset>
using namespace std;
int main(){
    for(int i = 0; i < 32; i++){
        cout << bitset<5>(i) << endl;
    }
    return 0;
}
/*
2的5次方 = 32
所以打印 0 —— 31
*/