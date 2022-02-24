/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 *
 * [1706] 球会落何处
 */

// @lc code=start
/** 
 * 模拟题
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, -1);

        // 遍历每个小球
        for (int i = 0; i < n; ++i)
        {
            int col = i; // 初始列
            // 每一行计算方向，模拟小球下落过程
            for (auto& row : grid)
            {
                // 下落方向，左 -1 或右 1
                int dir = row[col];
                col += dir;
                // 小球碰到边界或 v 形
                if (col < 0 || col >= n || row[col] != dir)
                {
                    col = -1;
                    break;
                }
            }
            res[i] = col;
        }

        return res;
    }
};
// @lc code=end

