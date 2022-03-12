/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i]: i 的二进制数中 1 的个数
 * 状态转移: 对于偶数，dp[i] = dp[i / 2]
 *          对于奇数，dp[i] = dp[i / 2] + 1
 * base case: dp[0] = 0
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 0)
                dp[i] = dp[i / 2];
            else
                dp[i] = dp[i / 2] + 1;
        }
        return dp;
    }
};
// @lc code=end

