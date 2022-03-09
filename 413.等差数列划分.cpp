/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i]: 以下标 i 结尾的等差数列个数为 dp[i]
 * 状态转移: if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
 *              dp[i] = dp[i-1] + 1
 * base case: 0
 */
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = 0;
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end

