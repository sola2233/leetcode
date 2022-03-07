/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i]: dp[i] 表示 i 之前包括 i 的最长上升子序列的长度
 * 状态转移: 对于每个 dp[i] 都要和之前的所有 dp[j] 对应的 nums[j] 比较，
 *          只有 nums[i] > nums[j]，dp[i] = max(dp[i], dp[j + 1])
 */
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // base case，全部初始化为 1
        vector<int> dp(n, 1);
        // 遍历
        int res = 1;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                    // 要和自己比，因为这里有很多满足条件的 dp[j]，要取其中最大的
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            // 取最长子序列
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

