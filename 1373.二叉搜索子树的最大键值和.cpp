/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 */

// @lc code=start
/** 
 * bst，递归
 * 1.明确递归函数的定义、返回值
 * res[0]: 是否是 bst
 * res[1]: 以 root 为根的 bst 最小值
 * res[2]: 以 root 为根的 bst 最大值
 * res[3]: 以 root 为根的 bst 键值和
 * 2.明确当前节点要做什么
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
#include <algorithm>
using namespace std;
class Solution {
public:
    int max_sum = INT32_MIN;
    int maxSumBST(TreeNode* root) {
        vector<int> res = traverse(root);

        return max_sum > 0 ? max_sum : 0;
    }

    // 遍历二叉树
    vector<int> traverse(TreeNode* root)
    {
        // base case，空节点
        if (root == nullptr)
            // 最大最小值要反过来，这样才能正确更新叶子节点
            return vector<int>{1, INT32_MAX, INT32_MIN, 0};

        // 递归遍历左右子树
        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);

        /** 后序位置更新 root 节点 */
        vector<int> res(4, 0); // 初始化为 0，默认不是 bst
        // 判断左右子树是否是 bst、判断 root 是否是 bst
        if (left[0] && right[0] && root->val > left[2] && root->val < right[1])
        {
            // 以 root 为根的二叉树是 BST
            res[0] = 1;
            // 计算以 root 为根的这棵 BST 的最小值
            res[1] = min(left[1], root->val);
            // 计算以 root 为根的这棵 BST 的最大值
            res[2] = max(right[2], root->val);
            // 计算以 root 为根的这棵 BST 所有节点之和
            res[3] = left[3] + right[3] + root->val;
            // 更新全局变量
            max_sum = max(max_sum, res[3]);
        }

        return res;
    }
};
// @lc code=end

