/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
/** 
 * 二分查找
 * 定义两个辅函数，LowerBound查找元素的第一个位置，UpperBound查找元素的最后一个位置
 * 两个辅函数的区别就是在nums[mid] == target时
 * LowerBound会把相等条件归到nums[mid] > target中，相当于在小于target的那一半里找target
 * UpperBound会把相等条件归到nums[mid] < target中，相当于在大于target的那一半里找target
 * 最后左指针l指向查找元素的最后一个位置的后一位，所以记得减一
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return vector<int> {-1, -1};
        }
        /** 获取左边界 */
        int lower = LowerBound(nums, target);
        /** 获取右边界，这里要减1 */
        int upper = UpperBound(nums, target) - 1;
        if (lower == nums.size() || nums[lower] != target)
        {
            return vector<int> {-1, -1};
        }
        return vector<int> {lower, upper};
    }

    /** 辅函数，获得下界 */
    int LowerBound(vector<int>& nums, int target)
    {
        /** 二分查找，左闭右开区间 */
        int l = 0;
        int r = nums.size();
        int mid = 0;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            /** 等于target时令r = mid */
            if (nums[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

    /** 辅函数，获得上界 */
    int UpperBound(vector<int>& nums, int target)
    {
        /** 二分查找，左闭右开区间 */
        int l = 0;
        int r = nums.size();
        int mid = 0;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            /** 等于target时令l = mid + 1 */
            if (nums[mid] > target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

