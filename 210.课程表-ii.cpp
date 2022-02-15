/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
/** 
 * 拓扑排序，通过遍历一遍图解决
 * 1.DFS，后序遍历的逆序就是可能结果之一，如果有环，has_cycle 就是 false
 * 2.BFS，bfs的顺序就是结果之一，如果有环，则遍历的节点数一定小于总节点数
 */
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    // 储存有向图，邻接表形式
    vector<vector<int>> graph;
    // 储存每个节点入度
    vector<int> indegree;
    // bfs查找环
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 分配大小，初始化内存
        graph.resize(numCourses);
        indegree.resize(numCourses);
        // 建图，同时构建入度数组
        for (auto& edge : prerequisites)
        {
            int from = edge[1], to = edge[0];
            graph[from].push_back(to);
            ++indegree[to];
        }

        // 入度为 0 的节点进入队列
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            // 这里不能用 auto for 循环，因为需要加入队列的值是节点，不是入度
            if (indegree[i] == 0)
                q.push(i);
        }

        // bfs
        vector<int> res; // 返回值
        while (!q.empty())
        {
            // 队列最前端元素出队列
            int cur = q.front();
            q.pop();
            // 放入答案中
            res.push_back(cur);
            // cur 节点指向的节点入度减一
            for (auto next : graph[cur])
            {
                --indegree[next];
                // 如果入度变为 0，说明 next 依赖的节点都已被遍历
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // res 本身的大小就可以计数，不用额外的变量计数
        if (res.size() == numCourses)
            return res;
        
        return {};
    }
};
// @lc code=end

