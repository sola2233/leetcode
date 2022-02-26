/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start
/** 
 * 利用中序遍历，交换两个数字有两种情况：
 * 1.交换不相邻两个数
 * 2.交换相邻两个数
 * 看 1 2 3 4 中序遍历序列
 * 交换 1 4 : 4 2 3 1，有两个逆序对，第一个逆序对的第一个和第二个逆序对的第二个交换
 * 交换 1 2 : 2 1 3 4，有一个逆序对，逆序对两个数交换
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
class Solution {
public:
    // 两个要交换的节点和上一个遍历的节点
    TreeNode *first, *second, *pre;

    void recoverTree(TreeNode* root) {
        first = nullptr;
        second = nullptr;
        pre = nullptr;
        traverse(root);

        // 交换
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

    // 中序遍历
    void traverse(TreeNode* root)
    {
        // base case
        if (root == nullptr)
            return;

        traverse(root->left);
        // 找到一个逆序对
        if (pre != nullptr && root->val < pre->val)
        {
            // 第一个逆序对
            if (first == nullptr)
            {
                first = pre;
                second = root;
            }
            // 第二个逆序对，写法可以再精简一点
            second = root;
        }
        pre = root;
        traverse(root->right);
    }
};
// @lc code=end

