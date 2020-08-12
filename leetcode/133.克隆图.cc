#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/*
1. 如何防止陷入循环拷贝(A -> B, B -> A)?
    - 用其他数据类型标记是否被拷贝；
    - 该数据类型必须有 key & value，key 用来保存原节点，value 用来保存新拷贝节点（需要返回该节点）；
    - 可以使用 map、unodered_map、数组；
    - 数组不错！因为 node 的 val 具有唯一性，可以用来做 key。

2. 如何拷贝完全？
    - 深度优先搜索；
    - 从第一个节点 A 开始，先拷贝该节点 A1；
    - 把该节点 A 的邻居 B，当作第一个节点 B，传入 cloneGraph 函数。
    - 并将 cloneGraph 函数返回的拷贝后的邻居节点 B1， 加入第一个节点的克隆体 A1 的邻居列表中。
*/

class Solution {
public:
    // 用数组标志是否拷贝过。
    Node* arr[101] = {nullptr};
    Node* cloneGraph(Node* node) {
        // 空节点直接返回。
        if (node == nullptr) {
            return nullptr;
        }

        // 拷贝过的节点直接返回。
        if (arr[node->val] != nullptr) {
            return arr[node->val];
        }

        // 拷贝当前节点，并放入数组标记
        Node* new_node = new Node(node->val);
        arr[node->val] = new_node;

        // 循环拷贝邻居节点 B，并放在 拷贝节点 A1 的邻居列表里。
        int n = node->neighbors.size();
        for (int i = 0; i < n; i++) {
            new_node->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return new_node;
    }
};