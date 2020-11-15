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
    void MyNotNull(TreeNode* root, int cur_num) {
        if (cur_num == num - 1) {
            if (root->left !=nullptr) {
                not_null_count++;
            }
            if (root->right !=nullptr) {
                not_null_count++;
            }
            return;
        }
        MyNotNull(root->left, cur_num + 1);
        MyNotNull(root->right, cur_num + 1);
        return;

    }
    int countNodes(TreeNode* root) {
        if (!root) { return 0; }
        if (!root->left && !root->right) { return 1; }
        TreeNode* tmp = root;
        while (tmp->left) {
            num++;
            tmp = tmp->left;
        }
        MyNotNull(root, 0);
        return pow(2, num) - 1 + not_null_count;
    }
private:
    int not_null_count = 0;
    int num = 0;
};


/*
时间复杂度 O(n)

1. 利用完全二叉树的特性。
2. 先遍历左子树的左节点，计算出层数 num。
3. 再递归遍历 num - 1 层时，是否为空，不为空，则最后一层的不为空节点加一（not_null_count++）

优化：二分搜索：https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/wan-quan-er-cha-shu-de-jie-dian-ge-shu-by-leetcode/
*/