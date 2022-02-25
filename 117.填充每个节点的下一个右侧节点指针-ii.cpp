/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/** 
 * 层次遍历
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

