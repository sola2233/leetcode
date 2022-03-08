/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
/** 
 * 动态规划
 * 还是和 1143 最长公共子序列好像
 * 找到最长公共子序列，再删掉其他字符就行了
 * dp[i][j]: 下标 i - 1 结尾的word1和下标 j - 1 结尾的 word2 最长公共子序列长度为 dp[i][j]
 * 状态转移: if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i-1][j-1] + 1
 *          else dp[i][j] = max(dp[i - 1][j], dp[i][j -1])
 * 方法2.直接动态规划计算最小删除次数
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // base case，初始化为 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int res = m - dp[m][n] + n - dp[m][n];
        return res;
    }
};
// @lc code=end

