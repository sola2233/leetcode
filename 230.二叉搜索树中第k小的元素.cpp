/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

// @lc code=start
/** 
 * bst，多利用中序遍历特性
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
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);

        return res;
    }

    int cnt = 0;
    int res = 0;
    // 递归函数，中序遍历
    void traverse(TreeNode* root, int k)
    {
        // base case
        if (root == nullptr)
            return;
        
        traverse(root->left, k);
        // 中序位置
        ++cnt;
        if (cnt == k)
        {
            res = root->val;
            return;
        }
        traverse(root->right, k);
    }
};
// @lc code=end

