#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* AddTreeNode(int begin, int end) {
        int size = end - begin + 1;
        int middle = middle = size / 2 + begin;
        TreeNode* tmp_ptr = new TreeNode;
        tmp_ptr->val = source[middle];
        if (begin < middle) {
            tmp_ptr->left = AddTreeNode(begin, middle - 1);
        } else {
            tmp_ptr->left = nullptr;
        }
        if (middle < end) {
            tmp_ptr->right = AddTreeNode(middle + 1, end);
        } else {
            tmp_ptr->right = nullptr;
        }
        return tmp_ptr;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* tmp_ptr = head;
        while(tmp_ptr) {
            source.push_back(tmp_ptr->val);
            tmp_ptr = tmp_ptr->next;
        }
        ans_tree = AddTreeNode(0, source.size() - 1);
        return ans_tree;
    }

public:
    vector<int> source;
    TreeNode* ans_tree;
};