/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        // 负例，需要保证队列中的节点都存在
        if (root == nullptr)
            return res;
        // 根节点入队列
        que.push(root);
        while (!que.empty())
        {
            int sz = que.size();
            vector<int> level; // 记录这一层的节点
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* p = que.front();
                que.pop();
                // 需要保证队列中节点不为空
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
                // 记录本层节点
                level.push_back(p->val);
            }
            res.push_back(level);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

