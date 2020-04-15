#include <bits/stdc++.h>

class CQueue {
public:
    stack<int> stack01;
    stack<int> stack02;

    CQueue() {

    }
    
    void appendTail(int value) {
            stack01.push(value);
    }
    
    int deleteHead() {
        if (stack02.empty()) {
            if (stack01.empty()) {
                return -1;
            } else {
                while (!stack01.empty()) {
                    stack02.push(stack01.top());
                    stack01.pop();
                }
            }
        }    
        int hand = stack02.top();
        stack02.pop();
        return hand;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */