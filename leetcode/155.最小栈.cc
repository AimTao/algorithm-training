#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {
        min_num.push(INT_MAX);
    }
    
    void push(int x) {
        min_num.push(min(min_num.top(), x));
        data.push(x);
    }
    
    void pop() {
        data.pop();
        min_num.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_num.top();
    }
private:
    stack<int> data;
    stack<int> min_num;
};