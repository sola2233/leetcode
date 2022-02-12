/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/** 
 * 二叉树问题
 * 递归解决：
 * 1.递归函数定义，利用这个定义推导结果，不要跳进递归细节
 * 2.root节点该做什么，什么时候做
 * 3.根据题目要求选择前序、中序、后序框架
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
class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        // base case
        if (root == nullptr)
            return root;
        
        // 递归翻转子节点
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};
// @lc code=end

