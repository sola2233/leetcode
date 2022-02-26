/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = build(inorder, 0, inorder.size() - 1, 
                                postorder, 0, postorder.size() - 1);

        return root;
    }

    // 递归函数，递归构建子树根节点，区间左闭右闭
    TreeNode* build(vector<int>& inorder, int in_start, int in_end, 
                    vector<int>& postorder, int post_start, int post_end)
    {
        // base case，叶子节点的哨兵节点
        // 此时有一个很重的点，就是中序数组大小一定是和后序数组的大小相同的（这是必然）
        if (in_start > in_end)
            return nullptr;

        // 构建根节点
        int root_val = postorder[post_end];
        TreeNode* root = new TreeNode(root_val);

        // 找到 inorder 中根节点位置 index，确定 root 左子树大小
        int index = in_start;
        for (int i = in_start; i <= in_end; ++i)
        {
            if (inorder[i] == root_val)
            {
                index = i;
                break;
            }
        }
        // 左子树长度
        int left_size = index - in_start;

        // 递归构建左右子树
        root->left = build(inorder, in_start, index - 1, 
                            postorder, post_start, post_start + left_size - 1);
        root->right = build(inorder, index + 1, in_end, 
                            postorder, post_start + left_size, post_end - 1);

        return root;
    }
};
// @lc code=end

