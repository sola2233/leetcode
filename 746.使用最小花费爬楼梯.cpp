/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i]: 从下标为 i 的台阶向上爬需要支付的费用，无论爬一步还是两步
 * 状态转移方程: dp[i] = min(dp[i-2], dp[i-1]) + cost[i]
 * base case: dp[0] = cost[0], dp[1] = cost[1]
 */
#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // 空间压缩
        vector<int> dp(2);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; ++i)
        {
            // dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
            int cur = min(dp[0], dp[1]) + cost[i];
            dp[0] = dp[1];
            dp[1] = cur;
        }

        return min(dp[0], dp[1]);
    }
};
// @lc code=end

