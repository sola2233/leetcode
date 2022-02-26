/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
 */

// @lc code=start
/** 
 * bst，bst代码框架
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
    // 递归
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     // base case，没找到
    //     if (root == nullptr)
    //         return root;
        
    //     // 递归，因为 bst 的特性，可以剪枝
    //     // 去左子树找
    //     if (root->val > val)
    //         return searchBST(root->left, val);
    //     // 去右子树找
    //     if (root->val < val)
    //         return searchBST(root->right, val);
    //     // 找到的情况，不能写在 else if 中，也可以并到 base case 中去，条件为或
    //     return root;
    // }

    // 迭代
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return root;
        
        while (root)
        {
            if (val < root->val)
                root = root->left;
            else if (val > root->val)
                root = root->right;
            else if (val == root->val)
                return root;
        }

        return nullptr;
    }
};
// @lc code=end

