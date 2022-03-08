/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i][j]: 以下标 i-1 结尾的 word1 子串和以下标 j-1 结尾的 word2 子串的最小编辑距离
 * 状态转移: if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1]
 *          不等情况 1.删 word1：dp[i][j] = dp[i-1][j] + 1
 *                  2.删 word2: dp[i][j] = dp[i][j-1] + 1
 *                  3.替换元素: dp[i][j] = dp[i-1][j-1] + 1
 *          其中添加元素和删除元素是一回事
 * base case: dp[i][0] = i，相当于删除 word1 中全部元素
 *            dp[0][j] = j，同理
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // base case
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

