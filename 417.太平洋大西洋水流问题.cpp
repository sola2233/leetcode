/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
/** 
 * 深度优先搜索
 * 从各边界开始逆流进行搜索。
 * 然后用两个二维数组进行记录，相当于进行了 4 次深度搜索
 * 最后还要再遍历一遍矩阵，寻找满足条件的位置
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> di{-1, 1,  0, 0};
    vector<int> dj{ 0, 0, -1, 1};
    
    /**
     * 主函数 
     * 位置示意：
     * 太平洋
     *      -------
     *      |     |
     *      |     |
     *      |     |
     *      -------
     *             大西洋
     * @param height 待搜索网格
     * @return 能通到两个洋的水流位置
     */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        // 网格为空的情况
        if (rows < 1 || cols < 1)
            return {};
        vector<vector<int>> ret;
        // 开辟的额外空间，表示是否能到太平洋 Pacific
        vector<vector<bool>> can_reach_p(rows, vector<bool>(cols, false));
        // 开辟的额外空间，表示是否能到大西洋 Atlantic
        vector<vector<bool>> can_reach_a(rows, vector<bool>(cols, false));
        // 遍历左右两条边，左边通太平洋，右边通大西洋
        for (int i = 0; i < rows; ++i)
        {
            // 搜索左边，找出哪些水流能通道太平洋
            dfs(heights, can_reach_p, i, 0);
            // 搜索右边，找出哪些水流能通道大西洋
            dfs(heights, can_reach_a, i, cols - 1);
        }
        // 遍历上下两条边，上边通太平洋，下边通大西洋
        for (int i = 0; i < cols; ++i)
        {
            // 搜索上边，找出哪些水流能通道太平洋
            dfs(heights, can_reach_p, 0, i);
            // 搜索下边，找出哪些水流能通道大西洋
            dfs(heights, can_reach_a, rows - 1, i);
        }
        // 遍历一遍矩阵，寻找满足条件的情况
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                // 两个洋都通的水流位置
                if (can_reach_p[i][j] && can_reach_a[i][j])
                    ret.push_back(vector<int>{i, j});
            }
        }
        return ret;
    }

    /**
     * 辅函数，深度优先搜索 
     * @param height 待搜索网格
     * @param can_reach 是否可到达 矩阵
     * @param cur_i 当前的位置 i
     * @param cur_j 当前的位置 j
     */
    void dfs(const vector<vector<int>> &height, vector<vector<bool>> &can_reach, int cur_i, int cur_j)
    {
        // 递归终止条件
        if (can_reach[cur_i][cur_j])
            return;
        // 当前位置标记为可到达
        can_reach[cur_i][cur_j] = true;
        int next_i, next_j;
        // 迭代搜索四邻域
        for (int i = 0; i < 4; ++i)
        {
            next_i = cur_i + di[i];
            next_j = cur_j + dj[i];
            if (next_i >= 0 && next_i < height.size()
                && next_j >= 0 && next_j < height[0].size()
                // 因为是反向搜索，所以只有水位更高才能到达
                && height[cur_i][cur_j] <= height[next_i][next_j])
            {
                dfs(height, can_reach, next_i, next_j);
            }
        }
    }
};
// @lc code=end

