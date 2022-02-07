/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/** 
 * BFS算法
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
    int minDepth(TreeNode* root) {
        // 负例
        if (root == nullptr)
            return 0;

        // 核心数据结构
        queue<TreeNode *> q;
        q.push(root);
        int step = 1; // 初始化为1，因为本身就是1层

        // 向下扩散
        while (!q.empty())
        {
            // 当前队列中的节点向四周节点扩散
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                // 判断是否到达终点
                if (!cur->left && !cur->right)
                    return step;
                // 将 cur 的相邻节点加入队列
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            // 递增深度
            ++step;
        }
        return 0;
    }
};
// @lc code=end

