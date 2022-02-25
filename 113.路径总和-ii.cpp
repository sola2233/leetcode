/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res; // 存放返回结果
    vector<int> path; // 存放某条路径
    int sum = 0;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // 负例
        if (root == nullptr)
            return res;
        // 遍历
        sum += root->val;
        path.push_back(root->val);
        traverse(root, targetSum);

        return res;
    }

    // 遍历
    void traverse(TreeNode* root, int target)
    {   
        // base case
        if (root->left == nullptr && root->right == nullptr)
        {
            if (sum == target)
                res.push_back(path);
            return;
        }

        if (root->left)
        {
            sum += root->left->val;
            path.push_back(root->left->val);
            traverse(root->left, target); // 递归
            sum -= root->left->val; // 回溯
            path.pop_back();
        }
        if (root->right)
        {
            sum += root->right->val;
            path.push_back(root->right->val);
            traverse(root->right, target);
            sum -= root->right->val;
            path.pop_back();
        }
    }
};
// @lc code=end

