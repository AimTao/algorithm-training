#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        if (hash.count(root) == 1) {
            return hash[root];
        }
        int sum = root->val;
        if (root->left != NULL) {
            sum += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != NULL) {
            sum += rob(root->right->left) + rob(root->right->right);
        }
        hash[root] = max(sum, rob(root->right) + rob(root->left));
        return hash[root];
    }

private:
    unordered_map<TreeNode*,int> hash;
};