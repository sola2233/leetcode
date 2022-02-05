/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
/** 
 * 动态规划问题
 * dp[i]：表示金额为 i 时，所需最少硬币个数
 * 状态转移方程：dp[i] = min(dp[i], dp[i-coin] + 1)，遍历所有可能 coin，留下最小的
 */
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp数组，数量加1是由于此处dp[i]的定义，取值加1是因为最大需要硬币数是amount，此处加1的值不可能取到
        vector<int> dp(amount+1, amount+1);
        // base case
        dp[0] = 0;
        // 自底向上，遍历所有状态取值
        for (int i = 0; i <= amount; ++i)
        {
            // 内循环，在所有可能中取最小值
            for (int coin : coins)
            {
                // 子问题无解直接跳过，等于0的情况没有放在base case里，所以在此处出现
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }

        // 不要忘了加上负例
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// @lc code=end

