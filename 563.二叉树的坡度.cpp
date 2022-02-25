/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    // 递归遍历
    int sum = 0; // 坡度之和
    int findTilt(TreeNode* root) {
        traverse(root);

        return sum;
    }

    // 遍历，返回子树节点之和(注意不是节点数，是节点值之和)
    int traverse(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        int left_sum = traverse(root->left);
        int right_sum = traverse(root->right);

        // 计算坡度
        if (left_sum == 0 && right_sum == 0)
            sum += 0;
        else
            sum += abs(left_sum - right_sum);
        
        return left_sum + right_sum + root->val;
    }
};
// @lc code=end

