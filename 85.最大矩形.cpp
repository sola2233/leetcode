/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
/** 
 * 动态规划，这是 221 最大正方形的思路，本题不是动态规划，太难了
 * dp[i][j]: 以 matrix[i-1][j-1] 为右下角的最大矩形边长
 * 状态转移: dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
 * base case: dp[i][j] = 0
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};
// @lc code=end

