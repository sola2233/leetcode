/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while (!que.empty())
        {
            int sz = que.size();
            int sum = 0; // 记录每一层节点和
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* p = que.front();
                que.pop();
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
                // 记录每一层节点和
                sum += p->val;
            }
            res = sum;
        }
        return res;
    }
};
// @lc code=end

