/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/** 
 * 二叉树问题，用递归解决
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
    // 递归函数，展开以 root 节点为根的二叉树
    void flatten(TreeNode* root) {
        // base case
        if (root == nullptr)
            return;
        
        // 递归子节点
        flatten(root->left);
        flatten(root->right);

        // 后序位置，更新 root，将两条子节点的链表和 root 串在一起
        // 1.左右子树已经是链表
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        // 2.将左子树作为右子树
        root->left = nullptr;
        root->right = left;
        // 3.将原先右子树接到当前右子树末端
        TreeNode* cur = root; // 用 root 不用 left，因为 left 可能为空，而 root 不会
        while (cur->right != nullptr)
            cur = cur->right;
        cur->right = right;
    }
};
// @lc code=end

