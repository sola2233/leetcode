/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
/** 
 * 动态规划，二维，两个状态
 */
#include <vector>
using namespace std;
class Solution {
public:
    // 优化，还可以空间压缩
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        // base case
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; ++j)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        // 遍历
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

