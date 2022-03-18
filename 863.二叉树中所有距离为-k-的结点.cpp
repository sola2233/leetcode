/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/** 
 * 方法1.建图 + bfs
 * 方法2.不需要建完整的图，只需要记录每个节点的父节点就行了，bfs 遍历的时候就往三个方向遍历：左、右、父亲
 */
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // 建图
        graph.resize(501);
        dfs(root);
        // bfs
        vector<int> res; // 结果
        queue<int> que; // 队列
        vector<bool> visited(501); // 防止重复访问
        que.push(target->val);
        visited[target->val] = true; // 标记已访问
        int dist = 0;
        while (!que.empty())
        {
            int sz = que.size();
            for (int i = 0; i < sz; ++i)
            {
                int cur = que.front();
                que.pop();
                for (auto& node : graph[cur])
                {
                    // 防止走回头路
                    if (visited[node])
                        continue;
                    que.push(node);
                    visited[node] = true;
                }
                // 添加距离为 k 的节点
                if (dist == k)
                    res.push_back(cur);
            }
            if (dist == k)
                break;
            dist++;
        }
        return res;
    }

    // dfs 建立无向图
    void dfs(TreeNode* root)
    {
        // base case
        if (root == nullptr)
            return;
        
        if (root->left)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if (root->right)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        dfs(root->left);
        dfs(root->right);
    }
};
// @lc code=end

