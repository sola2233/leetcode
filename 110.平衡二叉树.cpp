/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/** 
 * 递归子问题，干脆把递归和遍历分开来吧，虽然都是递归，但是遍历有模板
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
#include <algorithm>
using namespace std;
class Solution {
public:
    // 递归，用一个辅函数帮助我们计算
    bool isBalanced(TreeNode* root) {

        // 0 说明是空节点，也算平衡
        return GetHeight(root) == -1 ? false : true;
    }

    // 辅函数，递归计算高度
    int GetHeight(TreeNode* root)
    {
        // base case
        if (root == nullptr)
            return 0;
        
        // 递归子树
        int left_height = GetHeight(root->left);
        if (left_height == -1)
            return -1;
        int right_height = GetHeight(root->right);
        if (right_height == -1)
            return -1;
        // 计算高度，并判断是否平衡
        int height = max(left_height, right_height);
        // 如果不平衡，高度传回 -1，也可以设置一个全局辅助变量
        if (abs(left_height - right_height) > 1)
            return -1;

        return height + 1;
    }
};
// @lc code=end

