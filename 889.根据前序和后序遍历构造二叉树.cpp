/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

// @lc code=start
/** 
 * 二叉树问题，递归
 * 实际上前序和后序并不能构造二叉树
 * 这里用了一个假设：
 * 找到 preorder 根节点 root = preorder[0] 后，假设左子树存在，那么 preorder[1] 就是左子树根节点
 * 以此在 postorder 中找到左子树根节点，确定左子树大小
 * 实际上：
 * root 的左子树不一定存在，可以只有右子树，但是上述假设可以返回一个可能
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = build(preorder, 0, preorder.size() - 1, 
                                postorder, 0, postorder.size() - 1);

        return root;
    }

    // 递归函数
    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end, 
                    vector<int>& postorder, int post_start, int post_end)
    {
        TreeNode* root = new TreeNode();
        // 搞懂了，只剩两个元素时，递归左子树确实是一个元素，但右子树递归就没有元素了，为空
        if (pre_start > pre_end)
            return nullptr;
        // base case，叶子节点，这里是等号因为后面要找 root 左子树根节点，至少两个元素才行
        if (pre_start == pre_end)
        {
            root->val = preorder[pre_start];
            return root;
        }
        
        // 构建根节点
        int root_val = preorder[pre_start];
        root->val = root_val;

        // 在 postorder 中找到左子树根节点，确定左子树大小 left_size
        int root_left = preorder[pre_start+1];
        int index = post_start;
        for (int i = post_start; i <= post_end; ++i)
        {
            if (postorder[i] == root_left)
            {
                index = i;
                break;
            }
        }
        int left_size = index - post_start + 1;

        // 递归构建左右子树
        root->left = build(preorder, pre_start + 1, pre_start + left_size, 
                            postorder, post_start, index);
        root->right = build(preorder, pre_start + left_size + 1, pre_end, 
                            postorder, index + 1, post_end - 1);

        return root;
    }
};
// @lc code=end

