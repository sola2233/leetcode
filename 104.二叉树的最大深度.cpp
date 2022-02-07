/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/** 
 * 二叉树问题，通常有两种思路：
 * 1.遍历一遍二叉树得到答案
 * 2.通过分解问题计算出答案，通常是分解为子树的问题
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
#include <algorithm>
using namespace std;
// 方法1：遍历求解
class Solution {
public:
    int depth = 0; // 记录遍历到的节点深度
    int res = 0;   // 记录最大深度

    int maxDepth(TreeNode* root) {
        // dfs遍历二叉树，通过回溯法记录节点深度depth
        traverse(root);

        return res;
    }

    void traverse(TreeNode* root)
    {
        // 结束条件，到达叶子节点
        if (!root)
        {
            res = max(res, depth);
            return;
        }

        ++depth; // pre-order
        traverse(root->left);
        traverse(root->right);
        --depth; // post-order
    }
};
// @lc code=end

