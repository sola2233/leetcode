/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */

// @lc code=start
/** 
 * 贪心 + 二叉树，真是难
 * 贪心：
 * 叶子节点放不放摄像头省下了的摄像头数量是指数阶别的。
 * 所以我们要从下往上看
 * 局部最优：让叶子节点的父节点安摄像头，所用摄像头最少
 * 整体最优：全部摄像头数量所用最少！
 * 二叉树后序遍历需要返回子节点状态
 * 来看看这个状态应该如何转移，先来看看每个节点可能有几种状态：
 * 有如下三种，我们分别有三个数字来表示：
 * 0：该节点无覆盖
 * 1：本节点有摄像头
 * 2：本节点有覆盖
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
    int res;
    int minCameraCover(TreeNode* root) {
        // 最后还要检查头结点的覆盖情况
        if (traverse(root) == 0)
            res++;
        return res;
    }

    // 后序遍历，返回 root 节点的覆盖情况
    int traverse(TreeNode* root)
    {
        // base case，空节点设为覆盖状态，是为了让叶子节点是无覆盖状态
        if (root == nullptr)
            return 2;
        
        // 递归子树
        int left = traverse(root->left);
        int right = traverse(root->right);
        // 情况1.子节点都有覆盖
        if (left == 2 && right == 2)
            return 0;
        // 情况2.子节点有一个没覆盖到，要装摄像头
        else if (left == 0 || right == 0)
        {
            res++;
            return 1;
        }
        // 情况3.子节点有一个装了摄像头
        else // if (left == 1 || right == 1)
            return 2;
    }
};
// @lc code=end

