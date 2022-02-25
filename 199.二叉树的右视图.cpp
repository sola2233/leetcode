/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
/** 
 * 层次遍历
 * 题目有坑，不是右侧链，想象如果右子树为空，那么看到的就是左子树了
 * 实际上每层看到的是每层层次遍历最后一个节点
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
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        // 负例
        if (root == nullptr) return res;
        // 根节点入队列
        que.push(root);
        // 层次遍历
        while (!que.empty())
        {
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
                // 记录每一层最右侧节点
                if (i == sz - 1)
                    res.push_back(p->val);
            }
        }
        return res;
    }
};
// @lc code=end

