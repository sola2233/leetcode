/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
/** 
 * 二分图，遍历染色
 * dfs 或 bfs
 */
#include <vector>
using namespace std;
class Solution {
public:
    // 是否满足二分图性质，初始满足
    bool is_ok = true;
    // 访问数组，防止重复或走回头路
    vector<bool> visited;
    // 染色数组
    vector<bool> color;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited.resize(n);
        color.resize(n);

        // 因为图不一定连通，所以每个节点都要遍历一次
        for (int i = 0; i < n; ++i)
            traverse(graph, i);

        return is_ok;
    }

    // dfs，
    void traverse(vector<vector<int>>& graph, int v)
    {
        // 不满足二分图性质时，直接返回
        if (!is_ok)
            return;
        // 标记已访问
        visited[v] = true;
        // 递归遍历相邻节点
        for (int i : graph[v])
        {
            if (!visited[i])
            {
                // 没有访问过则相邻节点染上不同颜色
                color[i] = !color[v];
                traverse(graph, i);
            }
            else
            {
                // 访问过就比较颜色，这里可以不用返回，因为在递归函数开头就有 is_ok 为 false 的情况了
                if (color[i] == color[v])
                    is_ok = false;
            }
        }
    }
};
// @lc code=end

