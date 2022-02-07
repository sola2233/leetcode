/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/** 
 * 二叉树问题
 * 直径 = 
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
class Solution {
public:
    int res = 0;        // 二叉树直径，返回结果
    int diameter = 0;   // 每个节点计算直径
    int diameterOfBinaryTree(TreeNode* root) {

        maxDepth(root);

        return res;
    }

    int maxDepth(TreeNode* root)
    {
        // 递归结束条件，已经到叶子节点
        if (!root)
        {
            return 0;
        }

        int max_left = maxDepth(root->left);
        int max_right = maxDepth(root->right);

        // 后序位置顺便计算二叉树直径
        diameter = max_left + max_right;
        res = max(res, diameter);
        // 后序位置返回这个节点的最大深度depth，相当于把子树的深度数据通过返回值传递回上一层
        return max(max_left, max_right) + 1;
    }
};
// @lc code=end

