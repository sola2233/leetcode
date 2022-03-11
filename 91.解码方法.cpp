/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i]: s[0, i-1] 的解码总数为 dp[i]
 * 状态转移: 对于 s[i-1]，dp[i] = dp[i - 1] + dp[i - 2](如果 s[i-2, i-1] 合法的话)
 * base case: dp[0] = 1
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        // base case
        dp[0] = 1;
        // 遍历，不合法的情况有点多，1.越界的 2.和 0 有关的
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26))
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};
// @lc code=end

