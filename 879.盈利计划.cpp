/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 */

// @lc code=start
/** 
 * 动态规划，很难
 * 方法1.三维
 * dp[i][j][k] : 前 i 项工作，一共 j 个人完成，至少利润为 k 的方案数
 * 状态转移 : 
 * 初始化 : 
 * [方法1也可以不用累加和](https://leetcode.cn/problems/profitable-schemes/solution/ying-li-ji-hua-by-leetcode-solution-3t8o/)
 */
#include <vector>
using namespace std;

class Solution {
public:
#if 0   // 三维
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = 1e9 + 7;
        int len = group.size();

        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
        // base case
        dp[0][0][0] = 1;
        for (int i = 1; i <= len; ++i)  // 遍历工作
        {
            int members = group[i - 1];
            int earn = profit[i - 1];
            for (int j = 0; j <= n; ++j)    // 遍历人数
            {
                for (int k = 0; k <= minProfit; ++k)    // 遍历利润
                {
                    // 人员不够
                    if (j < members)
                        dp[i][j][k] = dp[i - 1][j][k];
                    else
                        // note 状态转移
                        dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - members][max(0, k - earn)]) % MOD;
                }
            }
        }

        int res = 0;
        // note 这里要累加，为什么有 0 个人的情况呢，因为 minProfit 可以为 0
        for (int j = 0; j <= n; ++j)
        {
            res += dp[len][j][minProfit];
            if (res >= MOD)
                res -= MOD;
        }

        return res;
    }
#endif


#if 1   // 二维
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = 1e9 + 7;
        int len = group.size();

        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        // base case
        for (int j = 0; j <= n; ++j)
            dp[j][0] = 1;
        for (int i = 1; i <= len; ++i)
        {
            int members = group[i - 1];
            int earn = profit[i - 1];
            for (int j = n; j >= members; --j)
            {
                for (int k = minProfit; k >= 0; --k)
                {
                    // note 需要在这里取模，不能在下面判断 dp[j][k] 是否大于 MOD
                    dp[j][k] = (dp[j][k] + dp[j - members][max(0, k - earn)]) % MOD;
                }
            }
        }

        // note 为什么这里不用累加
        return dp[n][minProfit];
    }

#endif
};
// @lc code=end

