/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
/** 
 * 动态规划
 * 规划不出来啊
 * dp[i][j]: 以 matrix[i-1][j-1] 为右下角的最大正方形边长
 * 状态转移: dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // 遍历
        int len = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                    len = max(len, dp[i][j]);
                }
            }
        }
        return len * len;
    }
};
// @lc code=end

