/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
/** 
 * 岛屿问题，用 dfs 解决
 * 已经访问过的岛屿修改为 0，相当于淹没岛屿，为了节省 o(n*m) 空间的访问标记矩阵 visited
 */
#include <vector>
using namespace std;
class Solution {
public:
    // 上、下、左、右方向遍历
    vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;

        // 遍历 grid
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        // 越界
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        // 已经访问过
        if (grid[i][j] == '0')
            return;

        // 标记访问过得岛屿，相当于淹没岛屿
        grid[i][j] = '0';
        // 递归遍历相邻节点
        for (auto dir : dirs)
        {
            dfs(grid, i+dir.first, j+dir.second);
        }
    }
};
// @lc code=end

