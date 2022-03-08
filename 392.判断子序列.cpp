/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
/** 
 * 方法1.动态规划
 * 和 1143 最长公共子序列很像，就是找 s 和 t 的最长公共子序列，看是否是 s
 * dp[i][j]: [0, i - 1] 的子串与 [0, j - 1] 的子串的最大公共子序列长度
 * 状态转移: if (s[i - 1] == t[i - 1]) dp[i][j] = dp[i - 1][j - 1] + 1
 *          else dp[i][j] = max(dp[i - 1][j], dp[i][j -1])
 * 方法2.双指针
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    // 动态规划
    // bool isSubsequence(string s, string t) {
    //     int m = s.size(), n = t.size();
    //     vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    //     for (int i = 1; i <= m; ++i)
    //     {
    //         for (int j = 1; j <= n; ++j)
    //         {
    //             // 字符相等
    //             if (s[i - 1] == t[j - 1])
    //                 dp[i][j] = dp[i - 1][j - 1] + 1;
    //             else
    //                 // dp[i][j] = max(dp[i -1][j], dp[i][j -1]);
    //                 // 不懂就看 carl
    //                 dp[i][j] = dp[i][j - 1];
    //         }
    //     }
    //     return dp[m][n] == s.size();
    // }

    // 双指针
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        return i == m;
    }
};
// @lc code=end

