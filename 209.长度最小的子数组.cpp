/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
/** 
 * 滑动窗口
 */
#include <vector>
#include <cstdint>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0, len = 1000000;
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
                sum -= nums[left];
                left++;
            }
        }

        return len == 1000000 ? 0 : len;
    }
};
// @lc code=end

