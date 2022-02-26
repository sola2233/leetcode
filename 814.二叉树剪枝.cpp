/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    // 方法1.遍历
    // TreeNode* pruneTree(TreeNode* root) {
    //     bool has_one = HasOne(root);
    //     // 负例
    //     if (!has_one)
    //         return nullptr;

    //     return root;
    // }

    // // 遍历，返回子树是否有 1
    // bool HasOne(TreeNode* root)
    // {
    //     // base case
    //     if (root == nullptr)
    //         return false;
    //     if (root->left == nullptr && root->right == nullptr)
    //     {
    //         if (root->val == 0)
    //             return false;
    //         else
    //             return true;
    //     }
        
    //     bool is_left_has = HasOne(root->left);
    //     bool is_right_has = HasOne(root->right);

    //     // 后序位置
    //     if (!is_left_has)
    //         root->left = nullptr;
    //     if (!is_right_has)
    //         root->right = nullptr;
        
    //     return (root->val == 1) || is_left_has || is_right_has;
    // }

    // 递归子树
    TreeNode* pruneTree(TreeNode* root) {
        // base case
        if (root == nullptr)
            return nullptr;

        // 递归子树
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // 当前节点逻辑，左右子树都为空，当前节点是 0 才移除这棵树
        if (root->left == nullptr && root->right == nullptr && root->val == 0)
            return nullptr;
        // 否则就正常返回
        return root;
    }
};
// @lc code=end

