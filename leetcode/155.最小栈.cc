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
        a.push(x);
    }
    
    void pop() {
        a.pop();
        min_num.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return min_num.top();
    }
private:
    stack<int> a;
    stack<int> min_num;
};