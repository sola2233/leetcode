/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
/** 
 * 利用中序遍历
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
#include <cstdint>
#include <algorithm>
using namespace std;
class Solution {
public:
    int min_diff = INT32_MAX; // 记录最小差值
    int getMinimumDifference(TreeNode* root) {
        traverse(root);

        return min_diff;
    }

    // 记录上一个节点
    TreeNode* pre_node = nullptr;
    // 递归遍历
    void traverse(TreeNode* root)
    {
        if (root == nullptr)
            return;
        
        traverse(root->left);
        // 中序位置
        if (pre_node != nullptr)
            min_diff = min(min_diff, root->val - pre_node->val);
        pre_node = root;
        traverse(root->right);
    }
};
// @lc code=end

