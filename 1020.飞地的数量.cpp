/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
/** 
 * 岛屿问题，用 dfs 解决
 * 与1254题类似
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        
        for (int j = 0; j < n; ++j)
        {
            // 淹没上边
            dfs(grid, 0, j);
            // 淹没下边
            dfs(grid, m-1, j);
        }

        for (int i = 0; i < m; ++i)
        {
            // 淹没左边
            dfs(grid, i, 0);
            // 淹没右边
            dfs(grid, i, n-1);
        }

        // 遍历 grid 求飞地单元格数目
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                    ++res;                
            }
        }

        return res;
    }

    // dfs遍历，淹没已访问岛屿
    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        // 边界条件
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        // 已访问过
        if (grid[i][j] == 0)
            return;

        // 标记已访问
        grid[i][j] = 0;
        // 递归遍历相邻节点
        for (auto dir : dirs)
            dfs(grid, i+dir.first, j+dir.second);
    }
};
// @lc code=end

