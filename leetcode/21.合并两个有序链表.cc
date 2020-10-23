#include <iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;
        ListNode* ptr1 = l1, * ptr2 = l2;
        while (ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                cur->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                cur->next = ptr2;
                ptr2 = ptr2->next;
            }
            cur = cur->next;
        }
        
        if (ptr1) {
            while (ptr1) {
                cur->next = ptr1;
                cur = cur->next;
                ptr1 = ptr1->next;
            }
        }

        if (ptr2) {
            while (ptr2) {
                cur->next = ptr2;
                cur = cur->next;
                ptr2 = ptr2->next;
            }
        }

        ans = ans->next;
        return ans;
    }
};