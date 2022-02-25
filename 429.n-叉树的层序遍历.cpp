/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> res;
        // 负例
        if (root == nullptr) return res;
        // 根节点入队列
        que.push(root);
        // 层次遍历
        while (!que.empty())
        {
            // 记录每一层的节点
            vector<int> level;
            // 自顶向下遍历
            int sz = que.size();
            for (int i = 0; i < sz; ++i)
            {
                // 同一层内遍历
                Node* p = que.front();
                que.pop();
                level.push_back(p->val);
                // 子节点入队列
                for (auto& child : p->children)
                    que.push(child);
            }
            // 记录答案
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end

