/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */

// @lc code=start
/** 
 * bst，bst框架
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // base case，找到插入位置
        if (root == nullptr)
            return new TreeNode(val);

        // 去左子树找
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        // 去右子树找
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        // 不会存在相等元素，所以 root->val == val 不存在，最后只会找到 base case
        return root;
    }
};
// @lc code=end

