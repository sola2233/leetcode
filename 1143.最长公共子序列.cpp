/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i][j]: 长度为 [0, i - 1] 的字符串 text1 与长度为 [0, j - 1] 的字符串 text2 的
 *           最长公共子序列为 dp[i][j]，方便后面实现
 * 状态转移: 如果 text1[i - 1] == text2[j - 1]，dp[i][j] = dp[i - 1][j - 1] + 1
 *          如果不同，dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        // base case，大小加 1
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end

