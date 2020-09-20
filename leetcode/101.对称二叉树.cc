#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void MySwap(TreeNode* root) {
        if (!root) {
            return;
        }
        MySwap(root->left);
        MySwap(root->right);
        swap(root->left, root->right);
        return;
    }
    bool MyIsSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (!left || !right) {
            return false;
        }

        if (left->val != right->val) { return false; }

        if (!MyIsSymmetric(left->left, right->left)) { return false; }
        if (!MyIsSymmetric(left->right, right->right)) { return false; }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        MySwap(root->right);
        return MyIsSymmetric(root->left, root->right);
    }
};

// 这题就相当于结合了 【100.相同的树】 和 【226.翻转二叉树】 两道题。