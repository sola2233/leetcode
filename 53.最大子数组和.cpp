/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
/** 
 * 方法1.暴力穷举
 * 方法2.贪心
 * 方法3.动态规划
 * dp[i]: 下标 i 之前包括 i 的数中连续子数组最大和为 dp[i]，必须以 nums[i] 结尾
 * 状态转移: dp[i] = max(nums[i], dp[i - 1] + nums[i])
 */
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;
class Solution {
public:
#if 0   // 方法1.暴力穷举
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT32_MIN, sum = 0;
        // 暴力，会超时
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += nums[j];
                max_sum = max(max_sum, sum);
            }
        }

        return max_sum;
    }
#endif

#if 0   // 方法2.贪心
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT32_MIN, sum = 0;

        // 贪心，对于连续和小于 0 一样成立
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            // 更新最大连续和
            if (sum > max_sum)
                max_sum = sum;
            // 重置连续和起始位置，相当于从下一个 i 开始累加
            if (sum < 0)
                sum = 0;
        }

        return max_sum;
    }
#endif

#if 1   // 方法3.动态规划
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        // base case
        dp[0] = nums[0];
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
#endif
};
// @lc code=end

