/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> res;
        // 负例
        if (root == nullptr) return res;
        // 根节点入队列
        que.push(root);
        // 层次遍历
        while (!que.empty())
        {
            // 累加一层内的值，最后计算均值
            double sum = 0.0;
            // 自顶向下遍历
            int sz = que.size();
            for (int i = 0; i < sz; ++i)
            {
                // 同一层内遍历
                TreeNode* p = que.front();
                que.pop();
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
                // 累加
                sum += p->val;
            }
            // 计算均值
            res.push_back(sum / sz);
        }
        return res;
    }
};
// @lc code=end

