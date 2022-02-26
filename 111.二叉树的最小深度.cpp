/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/** 
 * 方法1.BFS算法，即层次遍历
 * 方法2.递归，分解子问题
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
#include <queue>
using namespace std;
class Solution {
public:
    // 方法1.层次遍历
    // int minDepth(TreeNode* root) {
    //     // 负例
    //     if (root == nullptr)
    //         return 0;

    //     // 核心数据结构
    //     queue<TreeNode *> q;
    //     q.push(root);

    //     // 向下扩散
    //     int depth = 0;
    //     while (!q.empty())
    //     {
    //         // 当前队列中的节点向四周节点扩散
    //         int sz = q.size();
    //         // 递增深度
    //         ++depth;
    //         for (int i = 0; i < sz; ++i)
    //         {
    //             TreeNode *cur = q.front();
    //             q.pop();
    //             // 判断是否到达终点
    //             if (cur->left == nullptr && cur->right == nullptr)
    //                 return depth;
    //             // 将 cur 的相邻节点加入队列
    //             if (cur->left)
    //                 q.push(cur->left);
    //             if (cur->right)
    //                 q.push(cur->right);
    //         }
    //     }

    //     return 0;
    // }

    // 方法2.递归，分解子问题
    int minDepth(TreeNode* root) {
        // base case
        if (root == nullptr)
            return 0;
        
        // 递归子树
        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);

        int depth = 0;
        // 后序位置，赋值本层最小深度，有三种情况
        // 当一个左子树为空，右不为空，说明最小深度是 1 + 右子树的深度
        if (root->left == nullptr && root->right != nullptr)
            depth = right_depth;
        // 当一个右子树为空，左不为空，说明最小深度是 1 + 右子树的深度
        else if (root->left != nullptr && root->right == nullptr)
            depth = left_depth;
        // 都不为空时
        else
            depth = min(left_depth, right_depth);

        return depth + 1;
    }
};
// @lc code=end

