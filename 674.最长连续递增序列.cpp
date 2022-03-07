/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
/** 
 * 简单动态规划
 * dp[i]: 下标 i 之前包括 i 的数中，以 i 结尾的连续递增子序列长度
 */
#include <vector>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        // base case
        vector<int> dp(n, 1);
        // 遍历
        int res = 1;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

