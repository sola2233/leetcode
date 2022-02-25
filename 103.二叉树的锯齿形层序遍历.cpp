/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
/** 
 * 层次遍历
 */
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        // 负例
        if (root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);

        // 遍历
        bool flag = false; // 是否反转
        while (!que.empty())
        {
            int sz = que.size();
            vector<int> level;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* p = que.front();
                que.pop();
                level.push_back(p->val);
                // 子树进队列
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            if (flag)
                reverse(level.begin(), level.end());
            res.push_back(level);
            flag = !flag;
        }

        return res;
    }
};
// @lc code=end

