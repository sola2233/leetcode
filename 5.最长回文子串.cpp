/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
/** 
 * 动态规划，和 647 回文子串差不多
 * dp[i][j]: [i,j] 子串是不是回文
 * 状态转移: 有四种
 * base case: 全部为 false
 * 遍历顺序: 从下往上，从左往右
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string res; // 记录最长回文
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        dp[i][j] = true;
                        // 记录最长回文
                        if (j - i + 1 > res.size())
                            res = s.substr(i, j - i + 1);
                    }
                    else if (dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        // 记录最长回文
                        if (j - i + 1 > res.size())
                            res = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

