/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
/** 
 * dp 解决
 * 和198题类似，只是要分情况讨论
 * 1.偷第一间房屋，[0, n-2]
 * 2.不偷第一间房，[1, n-1]
 * 框架：
 * 状态转移方程：dp[i] = max(dp[i-1], dp[i-2]+nums[i])
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // 负例，只有一间房
        if (n == 1) return nums[0];
        // 选两种情况中结果较大的
        int res = max(RobRange(nums, 0, n - 2), RobRange(nums, 1, n - 1));

        return res;
    }

    // 方法2，空间 o(1)
    int RobRange(vector<int>& nums, int start, int end)
    {
        int n = nums.size();
        // base case
        int dp_pre_2 = 0, dp_pre_1 = 0;
        for (int i = start; i <= end; ++i)
        {
            // 状态转移
            int dp_i = max(dp_pre_1, dp_pre_2 + nums[i]);
            dp_pre_2 = dp_pre_1;
            dp_pre_1 = dp_i;
        }

        return dp_pre_1;
    }

    // 方法1，空间 o(n)
    // int RobRange(vector<int>& nums, int start, int end)
    // {
    //     int n = nums.size();
    //     vector<int> dp(n, 0);
    //     // base case
    //     dp[start] = nums[start];
    //     // start == end 情况
    //     if (start + 1 > end)
    //         return dp[end];
    //     dp[start + 1] = max(nums[start], nums[start + 1]);
    //     for (int i = start + 2; i <= end; ++i)
    //         // 状态转移
    //         dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    //     return dp[end];
    // }
};
// @lc code=end

