/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
 */

// @lc code=start
/** 
 * 类似于 236 最近公共子节点
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
    struct Result 
    {
        // 记录最深节点的公共祖先节点 node
        TreeNode* node;
        // 记录当前子树的最大深度
        int depth;
        Result(TreeNode* n, int d) : node(n), depth(d) {}
    };

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        Result res = GetMaxDepth(root);

        return res.node;
    }

    // 递归函数，返回以 root 为根的子树深度
    Result GetMaxDepth(TreeNode* root)
    {
        // base case
        if (root == nullptr)
            return Result(nullptr, 0);

        // 递归获得左右子树最大深度
        Result left = GetMaxDepth(root->left);
        Result right = GetMaxDepth(root->right);

        // 两棵子树最大深度相同
        if (left.depth == right.depth)
            return Result(root, left.depth + 1);            
        // 左子树最大深度更大
        else if (left.depth > right.depth)
            return Result(left.node, left.depth + 1);
        // 右子树最大深度更大
        return Result(right.node, right.depth + 1);
    }
};
// @lc code=end

