/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
 * dfs 遍历
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // base case
        if (root == nullptr)
            return 0;
        
        int left = rangeSumBST(root->left, low, high);
        int right = rangeSumBST(root->right, low, high);
        int val = left + right;
        if (root->val >= low && root->val <= high)
            val += root->val;
        return val;
    }
};
// @lc code=end

