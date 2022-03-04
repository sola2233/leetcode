/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
/**
 * 股票问题，一律 dp
 * 框架：
 * dp[i][k][0]：第 i 天 交易上限为 k 次此时没有持股的最大利润
 * dp[i][k][1]：第 i 天 交易上限为 k 次此时持股的最大利润
 * 结果：求 dp[n-1][K][0]，最后一天不持股时的最大利润
 * 状态转移方程：
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 * base case：
 * dp[-1][k][0] = 0, dp[-1][k][1] = -infinity
 * dp[i][0][0] = 0, dp[i][0][1] = -infinity
 * 
 * 此问题中 k 无限制，即 k = infinity，k-1 可以认为等于 k，约去 k，再加上手续费 fee：
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
 * base case：
 * 由 dp[-1][0] = 0, dp[-1][1] = -infinity 得到
 * dp[0][0] = 0, dp[0][1] = -prices[0] - fee
 */
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
class Solution {
public:
    // 方法1，o(1)
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT32_MIN;
        for (int i = 0; i < n; ++i)
        {
            // 状态转移方程
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
        }

        return dp_i_0;
    }

    // 方法1，o(n*2)
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2));

    //     for (int i = 0; i < n; ++i)
    //     {
    //         // base case
    //         if (i - 1 == -1)
    //         {
    //             dp[0][0] = 0;
    //             dp[0][1] = -prices[i] - fee;
    //             continue;
    //         }
    //         // 状态转移方程
    //         dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    //         dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee);
    //     }

    //     return dp[n-1][0];
    // }
};
// @lc code=end

