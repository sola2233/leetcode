/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
/** 
 * 贪心
 */
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT32_MIN, sum = 0;
        // 暴力，会超时
        // for (int i = 0; i < n; ++i)
        // {
        //     int sum = 0;
        //     for (int j = i; j < n; ++j)
        //     {
        //         sum += nums[j];
        //         max_sum = max(max_sum, sum);
        //     }
        // }

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
};
// @lc code=end

