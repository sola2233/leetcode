/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
/** 
 * 股票买卖问题，一律 dp 解决
 * 状态：有三个状态，天数、交易次数 k、持有或买卖，画一个状态机就可以得到状态转移方程
 * 选择：买卖、持有
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
 * 此问题中 k=1，得到状态转移方程：
 * dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
 * dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i])
 *             = max(dp[i-1][1][1], -prices[i])
 * 约去其中的 k：
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
 *          = max(dp[i-1][1], -prices[i])
 * 对于base case，作为特例：
 * 由 dp[-1][0] = 0, dp[-1][1] = -infinity，得到
 * dp[0][0] = max(dp[-1][0], dp[-1][1] + prices[0])
 *          = 0
 * dp[0][1] = max(dp[-1][1], -prices[0])
 *          = -prices[0]
 */
#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;
class Solution {
public:
    // 方法2，空间复杂度 o(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // base case
        int dp_i_0 = 0, dp_i_1 = INT32_MIN;
        for (int i = 0; i < n; ++i)
        {
            // 状态转移
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }

        return dp_i_0;
    }

    // 方法1，空间复杂度 o(n*2)
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2));

    //     for (int i = 0; i < n; ++i)
    //     {
    //         // base case
    //         if (i - 1 == -1)
    //         {
    //             dp[0][0] = 0;
    //             dp[0][1] = -prices[i];
    //             continue;
    //         }
    //         // 状态转移
    //         dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    //         dp[i][1] = max(dp[i-1][1], -prices[i]);
    //     }

    //     return dp[n-1][0];
    // }
};
// @lc code=end

