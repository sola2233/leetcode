/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        // p q 在 root 两边，root 就是最近公共祖先
        if ((p->val < root->val && q->val > root->val)
            || (p->val > root->val && q->val < root->val))
            return root;
        // root 就是 p 或 q
        else if (root == p || root == q)
            return root;

        // 递归子树，需要递归仅仅当 p q 在 root 同一侧时，只需要递归左右子树之一就行了
        TreeNode* ancestor = nullptr;
        if (p->val < root->val)
            // 递归左子树
            ancestor =  lowestCommonAncestor(root->left, p, q);
        else
            // 递归右子树
            ancestor =  lowestCommonAncestor(root->right, p, q);
        
        return ancestor;
    }
};
// @lc code=end

