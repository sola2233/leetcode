/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/** 
 * 方法1.遍历 + 回溯
 * 方法2.分解问题，递归
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

#if 0   // 遍历 + 回溯
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

        // 递归遍历子树
        if (root->left)
        {
            sum += root->left->val;
            path.push_back(root->left->val);
            traverse(root->left, target); // 递归
            sum -= root->left->val; // 回溯
            path.pop_back(); // 回溯
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
#endif

#if 1   // 分解问题递归，效率感觉低一些
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        // base case
        if (root == nullptr)
            return res;
        // 叶子节点
        if (root->left == nullptr && root->right == nullptr)
        {
            // 路径和等于目标
            if (targetSum == root->val)
            {
                res.push_back({root->val});
                return res;
            }   
            else    // 否则返回空值
                return res;
        }

        vector<vector<int>> left = pathSum(root->left, targetSum - root->val);
        vector<vector<int>> right = pathSum(root->right, targetSum - root->val);

        for (auto vec : left)
        {
            vector<int> tmp = {root->val};
            tmp.insert(tmp.end(), vec.begin(), vec.end());
            res.push_back(tmp);
        }
        for (auto vec : right)
        {
            vector<int> tmp = {root->val};
            tmp.insert(tmp.end(), vec.begin(), vec.end());
            res.push_back(tmp);
        }

        return res;
    }
#endif
};
// @lc code=end

