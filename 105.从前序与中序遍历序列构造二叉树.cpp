/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/** 
 * 二叉树问题，递归
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = build(preorder, 0, preorder.size() - 1, 
                                inorder, 0, inorder.size() - 1);

        return root;
    }

    // 递归函数，递归建立子树根节点，区间左闭右闭
    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end, 
                    vector<int>& inorder, int in_start, int in_end)
    {
        // base case，preorder 和 inorder 为空时，即叶子节点的哨兵节点
        if (pre_start > pre_end)
            return nullptr;
        
        // 前序位置，构建根节点，其实在后序构建也行
        int root_val = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val);

        // 找到 inorder 中的根节点位置，确定 root 的左子树大小
        int index = in_start;
        for (int i = in_start; i <= in_end; ++i)
        {
            if (inorder[i] == root_val)
            {
                index = i;
                break; // 提前结束
            }
        }
        int left_size = index - in_start; // 左子树大小

        // 递归构建左右子树
        root->left = build(preorder, pre_start + 1, pre_start + left_size, 
                            inorder, in_start, index - 1);
        root->right = build(preorder, pre_start + left_size + 1, pre_end, 
                            inorder, index + 1, in_end);

        return root;
    }
};
// @lc code=end

