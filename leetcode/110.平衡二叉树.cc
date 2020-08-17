#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    pair<bool, int> IsBalanced(TreeNode* root) {
        if (!root) { return make_pair(true, 0); }

        pair<bool, int> ans_left, ans_right;
        if (root->left) {
            ans_left = IsBalanced(root->left);
            if (!ans_left.first) {
                return make_pair(false, 0);
            }
        }
        if (root->right) {
            ans_right = IsBalanced(root->right);
            if (!ans_right.first) {
                return make_pair(false, 0);
            }
        }
        int diff = abs(ans_right.second - ans_left.second);
        int max_depth = max(ans_right.second, ans_left.second);
        if (diff <= 1) {
            return make_pair(true, max_depth + 1);
        }
        return make_pair(false, 0);
    }

    bool isBalanced(TreeNode* root) {
        if (IsBalanced(root).first) {
            return true;
        }
        return false;
    }
};