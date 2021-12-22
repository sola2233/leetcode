/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
/** 
 * 广度优先搜索
 */
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> di{-1, 1,  0, 0};
    vector<int> dj{ 0, 0, -1, 1};

    /**
     * 主函数，返回两个岛屿间的最短距离 
     * @param grid 输入的二维矩阵
     * @return level 两个岛屿间的最短距离
     */
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        // dfs寻找第一个岛屿，并把1全部赋值为2
        bool flipped = false;
        for (int i = 0; i < m; ++i)
        {
            if (flipped)
                break;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }
        // bfs寻找第二个岛屿，并把过程中经过的0复制为2
        int i, j;
        int level = 0;
        while (!points.empty())
        {
            // 一层层进行遍历
            ++level;
            int n_points = points.size();
            while (n_points--)
            {
                // 遍历某一层内所有节点
                auto p = points.front();
                int r = p.first, c = p.second;
                points.pop();   // 遍历完出队列
                for (int k = 0; k < 4; ++k)
                {
                    i = r + di[k];
                    j = c + dj[k];
                    if (i >= 0 && j >= 0 && i < m && j < n)
                    {
                        if (grid[i][j] == 2)
                            continue;
                        // 遍历直到遇到陆地，返回距离
                        if (grid[i][j] == 1)
                            return level;
                        // 如果是海洋就把位置放入points队列
                        points.push(pair<int, int>{i, j});
                        grid[i][j] = 2;
                    }
                }
            }
        }
        // 如果前面没有搜索到就返回0
        return 0;
    }

    /**
     * 辅函数，深度优先搜索 
     * @param points 保存搜索到的靠近陆地的海洋位置
     * @param grid 输入的二维矩阵
     * @param m 二维矩阵的行
     * @param n 二维矩阵的列
     * @param i 当前访问节点位置
     * @param j 当前访问节点位置
     */
    void dfs(queue<pair<int, int>> &points, vector<vector<int>> &grid, 
                int m, int n, int i, int j)
    {
        // 递归终止条件，越界或找到已访问过的陆地直接返回
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2)
            return;
        // 靠近陆地的海洋全部放进队列中
        if (grid[i][j] == 0)
        {
            points.push(pair<int, int>{i, j});
            return;
        }
        // 修改当前节点状态为已访问
        grid[i][j] = 2;
        // 递归访问四邻域
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i, j - 1);
        dfs(points, grid, m, n, i, j + 1);
    }
};
// @lc code=end

