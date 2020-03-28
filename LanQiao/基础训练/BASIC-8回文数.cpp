#include <iostream>
using namespace std;
int main(){
    for(int i = 1000; i < 10000; i++){
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100 % 10;
        int d = i /1000;
        if(a == d && b == c){
            cout << i << endl;
        }
    }
}