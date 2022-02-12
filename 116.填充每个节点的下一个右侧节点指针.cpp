/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/** 
 * 二叉树问题，用递归解决
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        // 负例
        if (root == nullptr)
            return root;

        connectTwoNode(root->left, root->right);

        return root;
    }

    // 递归函数，连接相邻两个节点
    void connectTwoNode(Node* node1, Node* node2)
    {
        // base case
        if (node1 == nullptr)
            return;

        // 前序位置，连接两个节点
        node1->next = node2;

        // 递归相同父节点的两个节点
        connectTwoNode(node1->left, node1->right);
        connectTwoNode(node2->left, node2->right);
        // 递归跨越父节点的两个节点
        connectTwoNode(node1->right, node2->left);
    }
};
// @lc code=end

