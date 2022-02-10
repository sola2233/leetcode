/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
/** 
 * 岛屿问题，用 dfs 解决
 * 与200题求岛屿数目相同，只是先遍历访问非封闭岛屿，即四条边上的岛屿
 */

#include <vector>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;

        for (int j = 0; j < n; ++j)
        {
            // 淹没上边岛屿
            dfs(grid, 0, j);
            // 淹没下边岛屿
            dfs(grid, m-1, j);
        }

        for (int i = 0; i < m; ++i)
        {
            // 淹没左边岛屿
            dfs(grid, i, 0);
            // 淹没右边岛屿
            dfs(grid, i, n-1);
        }

        // 遍历grid寻找封闭岛屿
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }

    // dfs遍历，过程中淹没岛屿，相当于记录访问矩阵
    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        // 边界条件
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        // 已经访问过或被淹没
        if (grid[i][j] == 1)
            return;

        // 标记为已访问，即淹没
        grid[i][j] = 1;
        // 递归遍历相邻节点
        for (auto dir : dirs)
        {
            dfs(grid, i+dir.first, j+dir.second);
        }
    }
};
// @lc code=end

