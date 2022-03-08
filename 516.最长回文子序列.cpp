/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
/** 
 * 和 647 会文子串不一样，那个是子串，这个是子序列，不要求连续
 * 方法1.动态规划，看 carl
 * dp[i][j]: 字符串 s 在 [i, j] 范围内最长的回文子序列的长度为 dp[i][j]
 * 状态转移: if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2
 *          不等时，dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
 *          加入s[j]的回文子序列长度为dp[i + 1][j]。
 *          加入s[i]的回文子序列长度为dp[i][j - 1]。
 * base case: dp[i][i] = 1
 * 遍历顺序: 从下往上，从左往右
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // base case
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        // 从下往上
        for (int i = n - 1; i >= 0; --i)
        {
            // 从左往右，j == i 的情况在 base case 里了
            for (int j = i + 1; j < n; ++j)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

