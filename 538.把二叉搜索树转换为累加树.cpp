/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start
/** 
 * bst，多利用中序遍历特性
 * 这一题反中序
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
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);

        return root;
    }

    int sum = 0;
    // 递归函数，中序遍历，但是交换左右子树遍历顺序
    void traverse(TreeNode* root)
    {
        if (root == nullptr)
            return;
        
        traverse(root->right);
        // 中序位置
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }
};
// @lc code=end

