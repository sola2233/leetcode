/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/** 
 * 二叉树问题，递归解决
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
#include <stdint.h>
using namespace std;
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        TreeNode* root = build(nums, 0, nums.size() - 1);

        return root;
    }

    // 递归函数，递归构建根节点，左闭右闭
    TreeNode* build(vector<int>& nums, int start, int end)
    {
        // base case，只有一个元素的情况包含在下面代码中了
        if (start > end)
            return nullptr;
        
        // 找到最大元素索引
        int index = -1, num_max = INT32_MIN;
        for (int i = start; i <= end; ++i)
        {
            if (nums[i] > num_max)
            {
                index = i;
                num_max = nums[i];
            }
        }

        // 递归构建子节点
        TreeNode* left = build(nums, start, index - 1);
        TreeNode* right = build(nums, index + 1, end);

        // 后序位置，构建根节点
        TreeNode* root = new TreeNode(num_max, left, right);

        return root;
    }
};
// @lc code=end

