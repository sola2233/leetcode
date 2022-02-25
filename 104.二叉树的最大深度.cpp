/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/** 
 * 二叉树问题
 * 方法1.用递归来解决的话通常有两种思路：
 * 1.遍历一遍二叉树得到答案
 * 2.通过分解问题计算出答案，通常是分解为子树的问题
 * 方法2.层次遍历
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
    // int depth = 0; // 记录遍历到的节点深度
    // int res = 0;   // 记录最大深度

    // int maxDepth(TreeNode* root) {
    //     // dfs遍历二叉树，通过回溯法记录节点深度depth
    //     traverse(root);

    //     return res;
    // }

    // // 方法1：遍历求解
    // void traverse(TreeNode* root)
    // {
    //     // 结束条件，到达叶子节点
    //     if (root == nullptr)
    //     {
    //         res = max(res, depth);
    //         return;
    //     }

    //     ++depth; // pre-order
    //     traverse(root->left);
    //     traverse(root->right);
    //     --depth; // post-order
    // }

    // 方法2.层次遍历
    // int maxDepth(TreeNode* root) {
    //     // 负例
    //     if (root == nullptr)
    //         return 0;
    //     queue<TreeNode*> que;
    //     que.push(root);
    //     // 层次遍历
    //     int depth = 0;
    //     while (!que.empty())
    //     {
    //         int sz = que.size();
    //         depth++;
    //         for (int i = 0; i < sz; ++i)
    //         {
    //             TreeNode* p = que.front();
    //             que.pop();
    //             // 子节点入队列
    //             if (p->left)
    //                 que.push(p->left);
    //             if (p->right)
    //                 que.push(p->right);
    //         }
    //     }

    //     return depth;
    // }

    // 方法1.分解问题
    int maxDepth(TreeNode* root) {
        // base case
        if (root == nullptr)
            return 0;
        
        // 递归
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);

        // 后序位置，获得子树的最大高度，记得加 1
        int depth = 1 + max(left_depth, right_depth);

        return depth;
    }
};
// @lc code=end

