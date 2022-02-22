/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
/** 
 * 二分搜索 + 贪心
 * x: 最大子数组和 max，范围 max(num[i]) 到 sum(num[i])
 * f(x): 限定最大子数组和为 max，此时能分成几个子数组，单调降
 * target: f(x) <= m
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        // 左闭右闭
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 计算 f(x)
            int n = Split(nums, mid);
            if (n < m)
                right = mid - 1;
            else if (n > m)
                left = mid + 1;
            else if (n == m)
                // 收缩右边界，达到搜索左边界的目的
                right = mid - 1;
        }
        return left;
    }

    // 辅函数，限定最大子数组和为 max，看能分成几个子数组
    int Split(vector<int>& nums, int max)
    {
        int sum = 0;
        int res = 1;
        for (auto& num : nums)
        {
            if (sum + num > max)
            {
                ++res;
                sum = num;
            }
            else
                sum += num;
        }
        return res;
    }
};
// @lc code=end

