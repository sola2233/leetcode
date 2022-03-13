/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
/** 
 * 方法1.dfs，需要两个 dfs，复杂度 o(n^2)
 * 方法2.方法1中有许多重复计算，可以利用前缀和
 */
class Solution {
public:
    // 以 root 为根的二叉树里节点值之和等于 targetSum 的路径数目
    int pathSum(TreeNode* root, int targetSum) {
        // base case
        if (root == nullptr)
            return 0;
        
        int ret = rootSum(root, targetSum);        
        ret += pathSum(root->left, targetSum); // 这里不用减
        ret += pathSum(root->right, targetSum);

        return ret;
    }
    // 返回以节点 root 为起点向下且满足路径总和为 targetSum 的路径数目
    int rootSum(TreeNode* root, int targetSum)
    {
        // base case
        if (root == nullptr)
            return 0;
        
        int ret = 0;
        if (root->val == targetSum)
            ret++;
        
        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;
    }
};
// @lc code=end

