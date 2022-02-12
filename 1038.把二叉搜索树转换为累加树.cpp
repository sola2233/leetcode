/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 把二叉搜索树转换为累加树
 */

// @lc code=start
/** 
 * 与 538 重复
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
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);

        return root;
    }

    int sum = 0;
    void traverse(TreeNode* root)
    {
        if (root == nullptr)
            return;
        
        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }
};
// @lc code=end

