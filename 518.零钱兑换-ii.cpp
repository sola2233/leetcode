/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
/** 
 * 动态规划，完全背包问题
 * dp[j]: 凑成总金额j的货币组合数为dp[j]
 * 状态转移: dp[j] = dp[j] + dp[j - coins[i]]
 * base case: 1
 */
#include <vector>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        // base case，这里要初始化为 1
        dp[0] = 1;
        // 遍历顺序是有讲究的，如果外层遍历背包，内层遍历物品，就是求得排列数了，本题求组合数
        // 遍历物品
        for (int i = 0; i < coins.size(); ++i)
        {
            // 遍历背包
            for (int j = coins[i]; j <= amount; ++j)
                dp[j] = dp[j] + dp[j - coins[i]];
        }
        return dp[amount];
    }
};
// @lc code=end

