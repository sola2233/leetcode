/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/** 
 * bst，递归
 * 返回值 vector<TreeNode*> 含义：所有可能情况的 bst 根节点
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res = build(1, n);
    
        return res;
    }

    // 递归构建所有 bst，返回 [lo, hi] 内所有可能 bst 的根节点
    vector<TreeNode*> build(int lo, int hi)
    {
        // base case，节点为空
        if (lo > hi)
            return vector<TreeNode*>{nullptr};

        // 穷举 [lo, hi] 内所有可能的根节点情况
        vector<TreeNode*> res;
        for (int i = lo; i <= hi; ++i)
        {
            // 递归得到左右子 bst 的所有情况的根节点
            vector<TreeNode*> left_bst = build(lo, i - 1);
            vector<TreeNode*> right_bst = build(i + 1, hi);
            // 构建以 i 为根节点的所有 bst
            for (auto left : left_bst)
            {
                for (auto right : right_bst)
                {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

