/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
/** 
 * 图的遍历，相当于多叉树的遍历，只是可能会有环
 */
#include <vector>
using namespace std;
class Solution {
public:
    // 所有可能路径
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // 维护当前走过的路径
        vector<int> path;
        // 遍历图
        traverse(graph, 0, path);

        return res;
    }

    // 图的遍历，dfs
    void traverse(vector<vector<int>>& graph, int s, vector<int>& path)
    {
        // 做选择：当前节点 s 加入 path
        path.push_back(s);
        // base case，结束条件，即到达终点
        int n = graph.size(); // 节点个数
        if (s == n - 1)
        {
            res.push_back(path);
            path.pop_back();
            return;
        }

        // 递归访问相邻节点
        for (int i : graph[s])
            traverse(graph, i, path);

        // 撤销选择：节点 s 移出 path
        path.pop_back();
    }
};
// @lc code=end

