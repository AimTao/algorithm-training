#include <iostream>
using namespace std;

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
    TreeNode* last_ptr = nullptr;
    void AllNodeGoToRight(TreeNode* root) {
        if (!root->left) {
            last_ptr = root;
        } else {
            AllNodeGoToRight(root->left);
        }
        if (root->right) {
            last_ptr->left = root->right;
            root->right = nullptr;
        }
        if (last_ptr->left) {
            AllNodeGoToRight(last_ptr->left);
        }
        return;
    }
    void AllNodeGoToLeft(TreeNode* root){
        if (!root->left) {
            return;
        } else {
            AllNodeGoToLeft(root->left);
        }
        root->right = root->left;
        root->left = nullptr;
        return;
    }
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        AllNodeGoToRight(root);
        AllNodeGoToLeft(root);
        return;
    }
};