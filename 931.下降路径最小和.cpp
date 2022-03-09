/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i][j]: 到达 (i, j) 的下降路径最小和为 dp[i][j]
 * 状态转移: dp[i][j] = min(dp[i-1][j-1], dp[i-1[j], dp[i-1][j+1]) + matrix[i][j]
 * base case: dp[0][j] = matrix[0][j]
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // base case
        for (int j = 0; j < n; ++j)
            dp[0][j] = matrix[0][j];
        // 遍历选择
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j == 0)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                else if (j == n - 1)
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + matrix[i][j];
                else
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]})
                                    + matrix[i][j];
            }
        }

        int res = dp[n - 1][0];
        for (int j = 0; j < n; ++j)
            res = min(res, dp[n - 1][j]);

        return res;
    }
};
// @lc code=end

