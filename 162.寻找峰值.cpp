/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
/** 
 * 二分搜索
 */
#include <vector>
#include <cinttypes>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        // 左闭右闭
        int res;
        while (left <= right)
        {
            // 需要处理 -1 和 n 的边界情况
            long mid = left + (right - left) / 2;
            // 向右是上坡，舍弃左边
            if (GetNum(nums, mid) < GetNum(nums, mid + 1))
                left = mid + 1;
            // 向左是上皮，舍弃右边
            else if (GetNum(nums, mid) < GetNum(nums, mid - 1))
                right = mid - 1;
            // 找到一个峰值
            else
            {
                res = mid;
                break;
            }
        }
        return res;
    }

    // 辅助函数，处理边界情况
    long GetNum(vector<int>& nums, int mid)
    {
        if (mid < 0 || mid >= nums.size())
            return INT64_MIN;
        return nums[mid];
    }
};
// @lc code=end

