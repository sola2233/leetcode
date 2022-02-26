/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // base case
        if (root == nullptr)
            return nullptr;

        TreeNode* trim_left = trimBST(root->left, low, high);
        TreeNode* trim_right = trimBST(root->right, low, high);

        // 可以确定，根节点左子树上的节点如果超界，只会小于 low
        if (root->val < low)
            return trim_right;
        // 根节点右子树上的节点如果超界，只会大于 high
        else if (root->val > high)
            return trim_left;
        // root 不超界情况
        else
        {
            root->left = trim_left;
            root->right = trim_right;
        }

        return root;
    }
};
// @lc code=end

