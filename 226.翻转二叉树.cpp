/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/** 
 * 二叉树问题
 * 递归解决：
 * 1.递归函数定义，利用这个定义推导结果，不要跳进递归细节
 * 2.root节点该做什么，什么时候做
 * 3.根据题目要求选择前序、中序、后序框架
 * 递归也分两种：
 * 1.遍历一遍二叉树
 * 2.分解成子问题，这就需要明确递归函数的定义了
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
#include <algorithm>
using namespace std;
class Solution {
public:
    // 方法2.分解成子问题
    // TreeNode* invertTree(TreeNode* root) {
    //     // base case
    //     if (root == nullptr)
    //         return root;
        
    //     // 递归翻转子节点
    //     TreeNode* left = invertTree(root->left);
    //     TreeNode* right = invertTree(root->right);

    //     root->left = right;
    //     root->right = left;

    //     return root;
    // }

    // 方法1.遍历一遍二叉树
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);

        return root;
    }

    // 前序后序位置都可以交换两个子树
    void traverse(TreeNode* root)
    {
        // base case
        if (root == nullptr)
            return;
        
        traverse(root->left);
        traverse(root->right);

        // 后序位置
        swap(root->left, root->right);
    }
};
// @lc code=end

