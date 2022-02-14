/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/** 
 * 二叉树，递归（遍历）
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 递归函数，返回 p 和 q 的最近公共节点
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if (root == nullptr)
            return nullptr;
        // 先序位置找到 p 或 q 直接返回，如果 p 或 q 在 root 的左右子树中
        // 说明 root 就是 p 和 q 的最近公共节点，逻辑上也是没问题的
        // 因为如果 root 还有父节点，另一个孩子返回一定是 nullptr，root 会一直返回到根节点
        if (root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 后序位置
        // 1.p q 都在以 root 为根的树中
        if (left != nullptr && right != nullptr)
            return root;
        // 2.p q 都不在以 root 为根的树中
        if (left == nullptr && right == nullptr)
            return nullptr;
        // 3.p q 有一个在以 root 为根的树中
        return left == nullptr ? right : left;
    }
};
// @lc code=end

