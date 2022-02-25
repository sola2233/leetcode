/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
#include <cstdint>
using namespace std;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        // 负例
        if (root == nullptr) return res;
        // 根节点入队列
        que.push(root);
        // 层次遍历
        while (!que.empty())
        {
            // 记录每一层最大值，32位够了
            int max_num = INT32_MIN;
            // 自顶向下遍历
            int sz = que.size();
            for (int i = 0; i < sz; ++i)
            {
                // 同一层内遍历
                TreeNode* p = que.front();
                // 记录最大值
                que.pop();
                if (p->val > max_num)
                    max_num = p->val;
                // 子节点入队列
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
            }
            // 记录最大值
            res.push_back(max_num);
        }
        return res;
    }
};
// @lc code=end

