/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
/** 
 * 本题其实就是尽量让石头分成重量相同的两堆，相撞之后剩下的石头最小
 * 这样就化解成01背包问题了
 * 还是不太清楚为什么能这样解。。。唉
 */
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:

#if 0   // 二维 dp
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        // dp[i][j]: 在下标[0, i]内选石头，在总重量 j 内能达到的最大重量
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // base case
        for (int j = stones[0]; j <= target; ++j)
            dp[0][j] = stones[0];
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= target; ++j)
            {
                if (j < stones[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[n - 1][target] * 2;
    }
#endif


#if 1   // 一维 dp
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        // dp[j]: 总重量 j 的背包，最多可以背的石头重量，不会超过 j
        vector<int> dp(target + 1, 0);
        // base case，初始化为 0 就行

        for (int i = 0; i < n; ++i)
        {
            for (int j = target; j >= stones[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[target] * 2;
    }
#endif
};
// @lc code=end

