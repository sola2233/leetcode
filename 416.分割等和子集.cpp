/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
/** 
 * 方法1.乍一看可以回溯，但是好像会超时，没有试
 * 方法2.动态规划，01背包问题
 * dp[j]: 容量为 j 的背包能装的最大价值，这里 value 和 weight 一样
 * 状态转移: dp[j] = max(dp[j], dp[j - nums[i]] + nums[i])
 * base case: i = 0 时，dp[j] = 0
 */
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:

#if 1   // 一维 dp，状态压缩，比二维 dp 快了好多
    // 一维
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 负例
        if (sum % 2 == 1 || n < 2) return false;
        // sum 最大 20000，这里只要 sum/2 即可，进一步优化为 target + 1
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = target; j >= nums[i]; --j)
            {
                // for 循环条件里已经保证没有这种情况了，如果 nums[i] > target，dp[j] 依然等于上次的值，不像二维数组需要再次赋值
                // if (j < nums[i])
                //     continue;
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
#endif


#if 0   // 二维 dp
    // dp[i][j]: 在下标 [0,i] 中选则数，能得到的最大总和
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 负例
        if (sum % 2 == 1 || n < 2) return false;
        // sum 最大 20000，这里只要 sum/2 即可，进一步优化为 target + 1
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // base case，i = 0
        for (int j = nums[0]; j <= target; ++j)
            dp[0][j] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= target; ++j)
            {
                if (j - nums[i] < 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }
        }

        return dp[n - 1][target] == target;
    }
#endif
};
// @lc code=end

