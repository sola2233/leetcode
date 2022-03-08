/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i][j]: 以 i-1 为结尾的 s 子序列中出现以 j-1 为结尾的 t 的个数为 dp[i][j]。
 * 状态转移: if (s[i - 1] == t[j - 1]) dp[i][j] == dp[i-1][j-1] + dp[i-1]dp[j]
 *          else dp[i][j] = dp[i - 1][j]
 * base case: dp[i][0] = 1，以 i-1 为结尾的 s 可以随便删除元素，出现空字符串的个数
 *            dp[0][j] = 0，空字符串 s 可以随便删除元素，出现以j-1为结尾的字符串t的个数
 *            dp[0][0] = 1，空字符串 s，可以删除 0 个元素，变成空字符串 t
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        // 不换成无符号 64 位会溢出
        vector<vector<u_int64_t>> dp(m + 1, vector<u_int64_t>(n + 1));
        // base case
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 1;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

