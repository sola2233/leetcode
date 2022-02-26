/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
/** 
 * 二叉树，递归，遍历一遍求解很容易，这里利用完全二叉树的性质降低时间复杂度
 * 这里利用完全二叉树的性质：左右子树必定有一棵为满二叉树
 * 思想：
 * 1.如果整个树不是满二叉树，就递归其左右孩子，直到遇到满二叉树为止，
 * 2.用公式计算这个子树（满二叉树）的节点数量。
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
#include <cmath>
using namespace std;
class Solution {
public:
    int countNodes(TreeNode* root) {
        // base case
        if (root == nullptr)
            return 0;
        
        // 查询左子树高度，一个节点高度为 1
        int hl = 0; // 从 root 开始，所以初始化为 0，如果从子树开始就初始化为 1
        TreeNode* left = root;
        while (left != nullptr)
        {
            ++hl;
            left = left->left;
        }

        // 查询右子树高度
        int hr = 0;
        TreeNode* right = root;
        while (right != nullptr)
        {
            ++hr;
            right = right->right;
        }

        // hl == hr 就是满二叉树，可以直接由高度计算节点
        if (hl == hr)
            return pow(2, hl) - 1;

        // 否则递归左右子树
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end

