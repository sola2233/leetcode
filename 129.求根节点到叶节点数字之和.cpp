/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
 */

// @lc code=start
/** 
 * 递归遍历，回溯
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
#include <numeric>
using namespace std;
class Solution {
public:
    vector<int> paths; // 存放所有路径
    int num = 0;
    int sumNumbers(TreeNode* root) {

        num += root->val;
        traverse(root);

        return accumulate(paths.begin(), paths.end(), 0);
    }

    void traverse(TreeNode* root)
    {
        // base case
        if (root->left == nullptr && root->right == nullptr)
        {
            paths.push_back(num);
            return;
        }

        // 遍历子树
        if (root->left)
        {
            num = num * 10 + root->left->val;
            traverse(root->left);
            num = (num - root->left->val) / 10;
        }
        if (root->right)
        {
            num = num * 10 + root->right->val;
            traverse(root->right);
            num = (num - root->right->val) / 10;
        }
    }
};
// @lc code=end

