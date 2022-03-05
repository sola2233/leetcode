/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
/** 
 * 方法1.动态规划，也分两种，dp函数递归（一定要带备忘录），dp数组
 * dp[i][j]: 从 (0, 0) 走到 (i, j) 有多少种走法
 * 转移方程: dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * base case: dp[0][0] = 1，如果 i < 0 或 j < 0 则 dp[i][j] = 0
 * 递归遍历不可取，会超时，因为就是穷举
 * 方法2.dfs
 * 方法3.bfs
 */
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        // base case
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 边界上的位置只有一种到达方法
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] =  dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

