/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i][j]: 从 (0, 0) 走到 (i, j) 有多少种走法
 * 转移方程: dp[i][j] = dp[i-1][j] + dp[i][j-1]
 *          如果 (i, j) 有障碍物，dp[i][j] = 0
 *          如果 (i-1, j) 有障碍物，dp[i][j] = dp[i][j - 1]
 *          如果 (i, j-1) 有障碍物，dp[i][j] = dp[i - 1][j]
 *          如果 (i-1, j) (i, j-1) 都有障碍物，dp[i][j] = 0
 * base case: dp[0][0] = 1，如果 i < 0 或 j < 0 则 dp[i][j] = 0
 * 递归遍历不可取，会超时，因为就是穷举
 */
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // base case，感觉 carl 的那种初始化方法我也挺喜欢的，可以看看
        dp[0][0] = 1 - obstacleGrid[0][0]; // 起点也可能是障碍物
        // 提前返回，不用做后面的计算了
        if (obstacleGrid[0][0])
            return 0;
        for (int i = 1; i < m; ++i)
        {
            // 只要有障碍物，以后的就到不了了，直接是 0
            if (obstacleGrid[i][0] == 1)
                break;
            // 这里要赋值为 dp[0][0]，主要为了处理 dp[0][0] 是 0 的情况
            dp[i][0] = dp[0][0];
        }
        for (int j = 1; j < n; ++j)
        {
            // 只要有障碍物，以后的就到不了了，直接是 0
            if (obstacleGrid[0][j] == 1)
                break;
            // 这里要赋值为 dp[0][0]，主要为了处理 dp[0][0] 是 0 的情况
            dp[0][j] = dp[0][0];
        }
        // 循环遍历
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0; // 可以 continue，因为初始化就是 0
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

