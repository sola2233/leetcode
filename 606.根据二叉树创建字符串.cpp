/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
#include <string>
using namespace std;
class Solution {
public:
    // 递归子树
    string tree2str(TreeNode* root) {
        // base case
        // 空节点
        if (root == nullptr)
            return "";
        // 左右子树都为空
        if (root->left == nullptr && root->right == nullptr)
            return to_string(root->val);

        // 递归子树
        string left_str = tree2str(root->left);
        string right_str = tree2str(root->right);

        // 左子树不为空，右子树为空的情况        
        if (root->right == nullptr)
            return to_string(root->val) + "(" + left_str + ")";
        // 其余两种情况：都不为空或左子树空、右子树不空
        return to_string(root->val) + "(" + left_str + ")" + "(" + right_str + ")";
    }
};
// @lc code=end

