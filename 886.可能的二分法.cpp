/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
/** 
 * 二分图，遍历
 */
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool is_ok = true; // 是否满足二分图性质
    vector<bool> visited; // 访问数组
    vector<bool> color; // 染色数组
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // 分配大小，初始化
        visited.resize(n+1);
        color.resize(n+1);
        // 建图，邻接表
        vector<vector<int>> graph(n+1);
        for (auto edge : dislikes)
        {
            // 无向图相当于双向图
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // bfs 遍历
        for (int i = 1; i < n+1; ++i)
        {
            // 因为图不一定连通，所以所有节点都要遍历
            if (!visited[i])
                bfs(graph, i);
        }
    
        return is_ok;
    }

    void bfs(vector<vector<int>>& graph, int start)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty() && is_ok)
        {
            // 队列首元素出队列
            int cur = q.front();
            q.pop();
            // 相邻节点加入队列
            for (auto next : graph[cur])
            {
                if (!visited[next])
                {
                    // 相邻节点未访问过
                    // 就将 next 加入队列，标记已访问
                    q.push(next);
                    visited[next] = true;
                    // 并染上不同颜色
                    color[next] = !color[cur];
                }
                else
                {
                    // 已访问过，则根据 cur 和 next 的颜色判断是否是二分图
                    if (color[next] == color[cur])
                        is_ok = false;
                }
            }
        }
    }
};
// @lc code=end

