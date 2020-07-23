#include <iostream>
#include <vector>
using namespace std;

int minArray(vector<int>& numbers) {
    int n = numbers.size();
    if (numbers[0] < numbers[n - 1]) {
        return numbers[0];
    }
    for (int i = 0; i < n - 1; i++) {
        if (numbers[i] > numbers[i + 1]) {
            return numbers[i + 1];
        }
    }
    return numbers[0];
}