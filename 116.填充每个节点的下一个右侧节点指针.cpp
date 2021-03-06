/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/** 
 * 二叉树问题
 * 方法1.用递归解决
 * 方法2.层次遍历
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
#include <queue>
using namespace std;
class Solution {
public:
    // 方法1.递归
    // Node* connect(Node* root) {
    //     // 负例
    //     if (root == nullptr)
    //         return root;

    //     connectTwoNode(root->left, root->right);

    //     return root;
    // }

    // // 递归函数，连接相邻两个节点
    // void connectTwoNode(Node* node1, Node* node2)
    // {
    //     // base case
    //     if (node1 == nullptr)
    //         return;

    //     // 前序位置，连接两个节点
    //     node1->next = node2;

    //     // 递归相同父节点的两个节点
    //     connectTwoNode(node1->left, node1->right);
    //     connectTwoNode(node2->left, node2->right);
    //     // 递归跨越父节点的两个节点
    //     connectTwoNode(node1->right, node2->left);
    // }

    // 方法2.层次遍历
    Node* connect(Node* root) {
        // 负例
        if (root == nullptr)
            return root;
        queue<Node*> que;
        que.push(root);
        // 层次遍历
        while (!que.empty())
        {
            int sz = que.size();
            for (int i = 0; i < sz; ++i)
            {
                Node* p = que.front();
                que.pop();
                // 连接
                if (i == sz - 1)
                    p->next = nullptr;
                else
                    p->next = que.front();
                // 子节点入队列
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
            }
        }

        return root;
    }
};
// @lc code=end

