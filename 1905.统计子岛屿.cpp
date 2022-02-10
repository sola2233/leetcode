/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 */

// @lc code=start
/** 
 * 岛屿问题，用 dfs 解决
 * 这题在 dfs 基础上，多了一些技巧性，把问题转化一下
 * 只要排除 grid2 中不是子岛屿的岛，剩下的岛就是子岛屿了
 * 只要 grid2 中的岛屿在 grid1 中有海洋，则就不是子岛屿
 * 提交的运行速度不是很快，LeetCode官方使用 bfs 来做的
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size();
        int res = 0;

        // 淹没 grid2 中不是子岛屿的岛
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 在 grid2 中是陆地，在 grid1 中是水域，就不是子岛屿
                if (grid2[i][j] == 1 && grid1[i][j] == 0)
                    dfs(grid2, i, j);
            }
        }

        // 遍历 grid2，剩下的都是子岛屿
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid2[i][j] == 1)
                {
                    ++res;
                    dfs(grid2, i, j);
                }
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
        // 已经访问过或被淹没
        if (grid[i][j] == 0)
            return;

        // 标记为已访问，淹没
        grid[i][j] = 0;
        // 递归遍历相邻子节点
        for (auto dir : dirs)
            dfs(grid, i+dir.first, j+dir.second);
    }
};
// @lc code=end

