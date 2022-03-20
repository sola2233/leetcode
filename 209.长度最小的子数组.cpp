/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
/** 
 * 方法1.暴力穷举 o(n^2)
 * 方法2.双指针，滑动窗口 o(n)
 */
#include <vector>
#include <cstdint>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0, len = INT32_MAX;
        // 左闭右开
        while (right < nums.size())
        {
            // 增大窗口，[left, right) 是窗口中的数
            sum += nums[right];
            right++;

            // 缩小窗口
            while (sum >= target)
            {
                // 更新答案
                if (len > right - left)
                {
                    len = right - left;
                }
                sum -= nums[left]; // 先减再加 left，顺序不能反
                left++;
            }
        }

        return len == INT32_MAX ? 0 : len;
    }
};
// @lc code=end

