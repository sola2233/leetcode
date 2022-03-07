/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
/** 
 * 动态规划，完全背包
 * 相当于物品是 nums[i] = i * i，背包容量是 n
 * dp[j]: 和为 j 的完全平方数最少为 dp[j]
 * 状态转移: dp[j] = min(dp[j], dp[j - nums[i]] + 1)
 * base case: 因为是最小，所以 dp[j] 要初始化为最大，这样才能覆盖
 *            dp[0] = 0
 * 遍历顺序: 两种 for 循环都行
 */
#include <vector>
#include <cstdint>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT32_MAX);
        // base
        dp[0] = 0;
        // 遍历物品，10^4 是完全平方数，他是 100 的平方
        for (int i = 1; i * i <= n; ++i)
        {
            int num = i * i;
            for (int j = num; j <= n; ++j)
            {
                // 防止溢出
                if (dp[j - num] != INT32_MAX)
                    dp[j] = min(dp[j], dp[j - num] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

