/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
/** 
 * 二分查找
 * 解题策略：
 * 即使数组被旋转过，依然可以使用二分查找。对于当前的中点 mid，
 * 如果 mid 指向的值小于等于右端，那么说明右区间 [mid+1, r] 是排好序的
 * 如果 mid 指向的值大于右端，那么说明左区间 [l, mid-1] 是排好序的。
 * 如果目标值 target 位于排好序的区间，就在这个区间二分查找，反之就在另一半区间二分查找。
 * 因为数组中存在重复数字，如果中点的值等于左端点的值，必然有一半区间是重复的，
 * 无法确认哪边是重复的，所以可以简单地将左端点右移一位。
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /** 二分查找，左闭右闭区间 */
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            /** 找到立即返回 */
            if (nums[mid] == target)
                return true;
            /** 中点的值等于左端点值时，左端点右移一位 */
            if (nums[mid] == nums[l])
                ++l;
            /** 如果右区间是排好序的 */
            else if (nums[mid] <= nums[r])
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            /** 如果左区间是排好序的 */
            else if (nums[mid] > nums[r])
            {
                if (target < nums[mid] && target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        /** 没找到返回false */
        return false;
    }
};
// @lc code=end

