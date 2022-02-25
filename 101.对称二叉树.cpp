/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/** 
 * 方法1.递归
 * 方法2.层次遍历，bfs
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
    // 方法1.递归
    bool isSymmetric(TreeNode* root) {
        // 题目中节点至少为 1，所以不用负例
        return Check(root->left, root->right);
    }

    // 递归函数，需要比较 左子树和右子树 的 里侧和外侧，每次都比较两个节点
    bool Check(TreeNode* left, TreeNode* right)
    {
        // 1.base case
        // 结构要相等，涵盖三种情况：某一个为空的两种情况 和 都为空的一种
        if (left == nullptr || right == nullptr)
            return left == right;
        // 值也要相等
        if (left->val != right->val)
            return false;
        
        // 2.递归，如果两个节点相等的话会一直递归，直到 base case 中的一种
        bool check_outside = Check(left->left, right->right);
        bool check_inside = Check(left->right, right->left);
        bool is_same = check_outside && check_inside;

        return is_same;
    }
};
// @lc code=end

