/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
/** 
 * bfs
 */
#include <queue>
using namespace std;
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // 负例，添加根节点
        if (depth == 1)
        {
            TreeNode* new_root = new TreeNode(val, root, nullptr);
            return new_root;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty() && depth > 1)
        {
            depth--;
            int sz = que.size();
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
                if (depth == 1)
                {
                    TreeNode* left = new TreeNode(val, cur->left, nullptr);
                    TreeNode* right = new TreeNode(val, nullptr, cur->right);
                    cur->left = left;
                    cur->right = right;
                }
            }
        }

        return root;
    }
};
// @lc code=end

