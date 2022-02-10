/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
/** 
 * 岛屿问题，用 dfs 解决
 * 这里给 dfs 函数设置返回值，记录每次淹没的岛屿个数，相当于面积
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int max_area = 0;

        // 遍历 grid
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 对每个为 1 的位置进行深度优先搜索，计算面积，保留最大的
                if (grid[i][j] == 1)
                    max_area = max(max_area, dfs(grid, i, j));
            }
        }

        return max_area;
    }

    // dfs遍历，淹没已访问岛屿，此处 dfs 增加了返回值，记录每次淹没的岛屿个数
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        // 边界条件
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;
        // 已访问过
        if (grid[i][j] == 0)
            return 0;

        // 标记为已访问
        grid[i][j] = 0;
        // 递归遍历相邻节点，记录淹没的岛屿个数
        int area = 0;
        for (auto dir : dirs)
            area += dfs(grid, i+dir.first, j+dir.second);

        // 返回值要加1，也可以直接初始化为1，放在这里逻辑上更清楚
        return area + 1;
    }
};
// @lc code=end

