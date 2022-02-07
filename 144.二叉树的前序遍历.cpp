/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/** 
 * 二叉树问题
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
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);

        return res;
    }

    void traverse(TreeNode *root)
    {
        if (root == nullptr)
            return;
        
        res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
};
// @lc code=end

