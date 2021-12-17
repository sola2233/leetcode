/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
/** 
 * 深度优先搜索
 * 一般来说，深度优先搜索类型的题可以分为主函数和辅函数，
 * 主函数用于遍历所有的搜索位置，判断是否可以开始搜索，
 * 如果可以即在辅函数进行搜索。
 * 辅函数则负责深度优先搜索的递归调用。
 * 递归相对便于实现，因此刷题时推荐使用递归式写法，
 * 在实际工程上，使用栈才是最好的选择
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> di{ 0, 0, -1, 1};
    vector<int> dj{-1, 1,  0, 0};

    /**
     * 主函数 
     * @param grid 待搜索网格
     * @return 最大面积
     */
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                // 对每个为 1 的位置进行深度优先搜索，计算面积，保留最大的
                if (grid[i][j] == 1)
                    max_area = max(max_area, dfs(grid, i, j));
            }
        }

        return max_area;
    }

    /**
     * 辅函数，深度优先搜索 
     * @param grid 待搜索网格
     * @param cur_i 当前的位置 i
     * @param cur_j 当前的位置 j
     * @return 当前位置及其邻域内的岛屿面积
     */
    int dfs(vector<vector<int>> &grid, int cur_i, int cur_j)
    {
        // 搜索到0直接返回
        if (grid[cur_i][cur_j] == 0)
            return 0;
        // 搜索过得 1 改为 0
        grid[cur_i][cur_j] = 0;
        // 加上当前位置的面积 1
        int next_i, next_j, area = 1;
        // 依次搜索四邻域
        for (int i = 0; i < 4; ++i)
        {
            next_i = cur_i + di[i];
            next_j = cur_j + dj[i];
            if (next_i >= 0 && next_i < grid.size() 
                && next_j >= 0 && next_j < grid[0].size())
            {
                area += dfs(grid, next_i, next_j);
            }
        }
        return area;
    }
};
// @lc code=end

