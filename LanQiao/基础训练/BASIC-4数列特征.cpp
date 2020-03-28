#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    cin  >> a[0];
    int min, max, sum;
    sum = min = max = a[0];
    for(int i = 1; i < n; i++){
        cin >> a[i];
        if(min > a[i]){
            min = a[i];
        }
        if(max < a[i]){
            max = a[i];
        }
        sum += a[i];
    }
    cout << max << endl << min << endl << sum;
    return 0;
}