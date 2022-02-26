/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
#include <algorithm>
using namespace std;
class Solution {
public:
    int res = -1;
    int findSecondMinimumValue(TreeNode* root) {
        int root_val = root->val;

        traverse(root, root_val);
        return res;
    }

    // 遍历一遍，找大于根节点值的最小节点
    void traverse(TreeNode* root, int root_val)
    {
        // base case
        if (root == nullptr)
            return;
        
        // 在大于 root_val 里找最小的值，没找到返回 res = -1
        if (root->val > root_val)
        {
            if (res == -1)
                res = root->val;
            else
                res = min(res, root->val);
            return;
        }

        traverse(root->left, root_val);
        traverse(root->right, root_val);
    }
};
// @lc code=end

