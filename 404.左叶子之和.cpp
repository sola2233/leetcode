/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    // 递归，后序位置
    int sumOfLeftLeaves(TreeNode* root) {
        // base case
        if (root == nullptr)
            return 0;
        // 递归子树
        int left_value = sumOfLeftLeaves(root->left);
        int right_value = sumOfLeftLeaves(root->right);
        int mid_value = 0; // 一开始没找到左叶子，mid、left、right 都是 0
        // 如果当前节点的左节点是一个左叶子
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            mid_value = root->left->val;
        int sum = mid_value + left_value + right_value;
        return sum;
    }
};
// @lc code=end

