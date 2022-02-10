/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
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
 * 此问题中 k=2，k 作为状态也要选择，而且 k >= 1，所以 dp 数组的空间应该为 k+1：
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 * base case：
 * 由 dp[-1][k][0] = 0, dp[-1][k][1] = -infinity
 *    dp[i][0][0] = 0, dp[i][0][1] = -infinity 得到
 * dp[0][k][0] = 0, dp[0][k][1] = -prices[0]
 * 因为 k=2，所以可以穷举
 * dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
 * dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i])
 *             = max(dp[i-1][1][1], -prices[i])
 * dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i])
 * dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i])
 */
#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;
class Solution {
public:
    // 方法2，o(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i_1_0 = 0, dp_i_1_1 = INT32_MIN;
        int dp_i_2_0 = 0, dp_i_2_1 = INT32_MIN;
        // 穷举 i
        for (int i = 0; i < n; ++i)
        {
            // 状态转移方程
            int temp = dp_i_1_0;
            dp_i_1_0 = max(dp_i_1_0, dp_i_1_1 + prices[i]);
            dp_i_1_1 = max(dp_i_1_1, -prices[i]);
            dp_i_2_0 = max(dp_i_2_0, dp_i_2_1 + prices[i]);
            dp_i_2_1 = max(dp_i_2_1, temp - prices[i]);
        }

        return dp_i_2_0;
    }

    // 方法1，o(n*3*2)
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2)));

    //     // k = 0 时的 base case
    //     for (int i = 0; i < n; ++i)
    //     {
    //         // 实际上不用这一步，因为 dp 初始化为0，状态转移只用到了 dp[i][0][0] = 0
    //         dp[i][0][1] = INT32_MIN;
    //         dp[i][0][0] = 0;
    //     }   
    //     // 穷举 i
    //     for (int i = 0; i < n; ++i)
    //     {
    //         // 穷举 k
    //         for (int k = 2; k >= 1; --k)
    //         {
    //             // base case
    //             if (i - 1 == -1)
    //             {
    //                 dp[0][k][0] = 0;
    //                 dp[0][k][1] = -prices[i];
    //                 continue;
    //             }
    //             // 状态转移方程
    //             dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
    //             dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
    //         }
    //     }

    //     return dp[n-1][2][0];
    // }
};
// @lc code=end

