/*
 * @lc app=leetcode.cn id=2039 lang=cpp
 *
 * [2039] 网络空闲的时刻
 */

// @lc code=start
/** 
 * 建图 + bfs
 * 1.bfs 计算主服务器到每个数据服务器的最短路径，记为 dist，则收发一条信息耗时 2 * dist
 * 2.计算在 2 * dist - 1 时间内数据服务器发出的消息总数，记为 num = (2 * dist - 1) / patience[v]
 * 3.每个数据服务器到空闲的时间为 patience[v] * num + 2 * dist + 1，最后加 1 是因为下一秒网络才没有数据
 * 4.找出最长的时间，即为该计算机网络变为空闲状态的时间
 */
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        // 建图，邻接表
        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> que;
        que.push(0);
        visited[0] = true;
        int dist = 0;
        int res = 0;
        while (!que.empty())
        {
            int sz = que.size();
            dist++; // 进入每一层先递增
            for (int i = 0; i < sz; ++i)
            {
                int cur = que.front();
                que.pop();
                for (int& v : adj[cur])
                {
                    // 防止走回头路
                    if (visited[v])
                        continue;
                    que.push(v);
                    visited[v] = true; // 标记已访问
                    // 计算节点 v 变为空闲状态的耗时
                    int num = (2 * dist - 1) / patience[v];
                    int time = patience[v] * num + 2 * dist + 1;
                    res = max(res, time);
                }
            }
        }
        return res;
    }
};
// @lc code=end

