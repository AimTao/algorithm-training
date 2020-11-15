#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 先遍历求长度，再遍历到倒数第k位。
    // ListNode* getKthFromEnd(ListNode* head, int k) {
    //     int length = 0;
    //     ListNode* ans_ptr = head;
    //     while (head) {
    //         length++;
    //         head = head->next;
    //     }
    //     int ans_index = length + 1 - k;
    //     while(--ans_index) {
    //         ans_ptr = ans_ptr->next;
    //     }
    //     return ans_ptr;
    // }

    // 空间换时间，将节点指针储存再数组里。
    // ListNode* getKthFromEnd(ListNode* head, int k) {
    //     vector<ListNode*> memo;
    //     while (head) {
    //         memo.push_back(head);
    //         head = head->next;
    //     }
    //     return memo[memo.size() - k];
    // }

    // 快慢指针，只遍历一次，性能较好。
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* cur_ptr = head;
        while (--k) {
            cur_ptr = cur_ptr->next;
        }
        while (cur_ptr != nullptr) {
            cur_ptr = cur_ptr->next;
            head = head->next;
        }
        return head;
    }
};