/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
#if 0   // 类似后序遍历，又有点不像。。。
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // base case
        if (root == nullptr)
            return nullptr;

        TreeNode* trim_left = trimBST(root->left, low, high);
        TreeNode* trim_right = trimBST(root->right, low, high);

        // 可以确定，根节点左子树上的节点如果超界，只会小于 low
        if (root->val < low)
            return trim_right;
        // 根节点右子树上的节点如果超界，只会大于 high
        else if (root->val > high)
            return trim_left;
        // root 不超界情况
        else
        {
            root->left = trim_left;
            root->right = trim_right;
        }

        return root;
    }
#endif

#if 1   // 递归分解问题
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // base case
        if (root == nullptr)
            return root;
        // 寻找符合区间[low, high]的节点
        if (root->val < low)
            return trimBST(root->right, low, high);
        if (root->val > high)
            return trimBST(root->left, low, high);

        // root->left接入符合条件的左孩子
        root->left = trimBST(root->left, low, high);
        // root->right接入符合条件的右孩子
        root->right = trimBST(root->right, low, high);

        return root;
    }
#endif
};
// @lc code=end

