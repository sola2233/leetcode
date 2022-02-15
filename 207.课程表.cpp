/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
/** 
 * 图的环路检测，通过遍历图来检测
 * 1.DFS
 * 2.BFS
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool has_cycle = false; // 表示是否有环
    vector<bool> visited; // 标记已访问的节点
    vector<bool> on_path; // 路径上的节点，表示目前在栈中的节点
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 分配大小，reserve并没有对内存进行初始化，而resize会
        visited.resize(numCourses);
        on_path.resize(numCourses);
        // 先建图
        vector<vector<int>> graph(buildGraph(numCourses, prerequisites));
        // 遍历一遍检测环
        for (int i = 0; i < numCourses; ++i)
            traverse(graph, i);
        // 没有环才能学完课程
        return !has_cycle;
    }

    // dfs，从节点 s 开始遍历 graph 中相邻节点
    void traverse(vector<vector<int>>& graph, int s)
    {
        // s 节点已经在路径中表示有环
        if (on_path[s])
        {
            has_cycle = true;
        }

        // 如果已访问过或者有环，直接返回
        if (visited[s] || has_cycle)
            return;

        // 标记已访问
        visited[s] = true;
        // 做出选择：加入路径
        on_path[s] = true;

        // 递归遍历相邻节点
        for (int i : graph[s])
        {
            traverse(graph, i);
        }

        // 后序位置，撤销选择
        on_path[s] = false;
    }

    // 建图，邻接表形式
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        // 分配大小
        vector<vector<int>> graph(numCourses);

        for (auto edge : prerequisites)
        {
            // 添加一条从 from 指向 to 的有向边
            // 边的方向是「被依赖」关系，即修完课程 from 才能修课程 to
            int from = edge[1], to = edge[0];
            graph[from].push_back(to);
        }

        return graph; 
    }
};
// @lc code=end

