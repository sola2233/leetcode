/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
 * 二叉树后序遍历，需要子树传递子节点的半条最大路径和，这里的半条指路径要从子节点开始
 * 遍历过程中维护一个全局变量 res，首先计算每个节点的最大路径和，再记录所有节点中最大路径和
 */
#include <algorithm>
#include <cstdint>
using namespace std;
class Solution {
public:
    int res; // 记录最大路径和
    int maxPathSum(TreeNode* root) {
        res = INT32_MIN;
        travserse(root);
        return res;
    }

    // 计算从根节点 root 为起点的最大单边路径和
    int travserse(TreeNode* root)
    {
        // base case
        if (root == nullptr)
            return 0;

        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        // 如果是负数，其实两个子节点的单边最大路径和都没有用了，直接返回 root->val
        int left = max(0, travserse(root->left));
        int right = max(0, travserse(root->right));
        
        int path_sum = left + right + root->val;
        res = max(res, path_sum);
        return max(left, right) + root->val;
    }
};
// @lc code=end

