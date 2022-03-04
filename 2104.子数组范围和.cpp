/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */

// @lc code=start
/** 
 * 方法1.暴力，不知道为什么我回溯写的不对，虽然和暴力差不多
 * 方法2.单调栈
 */
#include <vector>
#include <cstdint>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        // 遍历数组，选择开始下标
        for (int i = 0; i < n; i++)
        {
            int min_val = INT32_MAX, max_val = INT32_MIN;
            // 遍历子数组
            for (int j = i; j < n; j++)
            {
                min_val = min(min_val, nums[j]);
                max_val = max(max_val, nums[j]);
                res += max_val - min_val;
            }
        }
        return res;
    }
};
// @lc code=end

