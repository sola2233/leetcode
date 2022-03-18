/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
/** 
 * bfs
 * 父节点的位置为 pos(从 0 开始)
 * 左子节点位置为 2 * pos
 * 右子节点位置为 2 * pos + 1
 */
#include <queue>
using namespace std;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // 有符号整数会溢出，要换成无符号整数，pair.second 记录每层节点位置
        queue<pair<TreeNode*, unsigned int>> que;
        que.push(make_pair(root, 0));
        int res = 0;
        while (!que.empty())
        {
            int sz = que.size();
            int width = 0; // 每层宽度
            for (int i = 0; i < sz; ++i)
            {
                auto cur = que.front();
                que.pop();
                if (cur.first->left) que.push(make_pair(cur.first->left, 2 * cur.second));
                if (cur.first->right) que.push(make_pair(cur.first->right, 2 * cur.second + 1));
                // 计算本层宽度
                if (i == 0)
                    width -= cur.second;
                if (i == sz - 1)
                    width += cur.second;
            }
            res = max(res, width + 1);
        }
        return res;
    }
};
// @lc code=end

