/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
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
 * 此问题中 k=int，k 作为状态也要选择，而且 k >= 1，所以 dp 数组的空间应该为 k+1：
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 * base case：
 * 由 dp[-1][k][0] = 0, dp[-1][k][1] = -infinity
 *    dp[i][0][0] = 0, dp[i][0][1] = -infinity 得到
 * dp[0][k][0] = 0, dp[0][k][1] = -prices[0]
 * 要提前把 k = 0 的 base case 初始化一下
 */
#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // 负例
        if (n == 0 || k == 0)
            return 0;
        // 一次交易需要两天，当 k >= n / 2 时，相当于 k = infinity
        k = min(k, n / 2); // 若不限制 k 会造成内存溢出
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2)));
        
        // k = 0 时的 base case
        for (int i = 0; i < n; ++i)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT32_MIN;
        }   
        // 穷举 i
        for (int i = 0; i < n; ++i)
        {
            // 穷举 k
            for (int j = k; j >= 1; --j)
            {
                // base case
                if (i - 1 == -1)
                {
                    dp[0][j][0] = 0;
                    dp[0][j][1] = -prices[i];
                    continue;
                }
                // 状态转移方程
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }

        return dp[n-1][k][0];
    }
};
// @lc code=end

