/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    // 递归函数，递归遍历
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        // 如果两个都为空
        if (p == nullptr && q == nullptr)
            return true;
        // 如果只有一个为空
        else if (p == nullptr || q == nullptr)
            return false;
        // 如果两个都不空，结点值也不同，那直接返回false
        else if (p->val != q->val)
            return false;

        // 如果现在结点值和子树结点值相同，再分别检查两个的左右孩子
        // 递归遍历子树
        bool is_same_left = isSameTree(p->left, q->left);
        bool is_same_right = isSameTree(p->right, q->right);

        return is_same_left && is_same_right;
    }
};
// @lc code=end

