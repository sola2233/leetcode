/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
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
 * 此问题中 k 无限制，即 k = infinity，k-1 可以认为等于 k，约去 k：
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
 * base case：
 * 由 dp[-1][0] = 0, dp[-1][1] = -infinity 得到
 * dp[0][0] = 0, dp[0][1] = -prices[0]
 */
#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;
class Solution {
public:

#if 1   // 方法3，贪心

    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        // 利润和可以分解成差分数组的形式
        for (int i = 1; i < prices.size(); ++i)
            max_profit += max(0, prices[i] - prices[i - 1]);

        return max_profit;
    }

#endif


#if 0   // 方法2，空间复杂度 o(1)
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // base case
        int dp_i_0 = 0, dp_i_1 = INT32_MIN;         
        for (int i = 0; i < n; ++i)
        {
            // 状态转移方程
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }

        return dp_i_0;
    }
#endif


#if 0   // 方法1，空间复杂度 o(n*2)

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        
        for (int i = 0; i < n; ++i)
        {
            // base case
            if (i - 1 == -1)
            {
                dp[0][0] = 0;
                dp[0][1] = -prices[i];
                continue;
            }
            // 状态转移方程
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return dp[n-1][0];
    }
#endif
};
// @lc code=end

