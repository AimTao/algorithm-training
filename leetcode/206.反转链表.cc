#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* ans = nullptr;

void MyReverseList(ListNode* head, ListNode* old_head) {
    if (head->next == nullptr) {
        head->next = old_head;
        ans = head;
        return;
    }
    MyReverseList(head->next, head);
    head->next = old_head;
    return;
}

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    MyReverseList(head->next, head);
    head->next = nullptr;
    return ans;
}

int main() {
    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    a.next = &b;
    b.next = &c;
    c.next = nullptr;
    ListNode* p = reverseList(&a);
    while (p != nullptr) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}