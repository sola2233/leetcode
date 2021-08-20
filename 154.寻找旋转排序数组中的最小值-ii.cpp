/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
/** 
 * 二分查找
 * [leetcode题解]
 * (https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/154-find-minimum-in-rotated-sorted-array-ii-by-jyd/)
 */
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        /** 右指针等于数组长度减一，不然会越界 */
        int r = nums.size() - 1;
        int mid = 0;
        /** 实际上还是个左闭右开区间 */
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] < nums[r])
            {
                r = mid;
            }
            else if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else if (nums[mid] == nums[r])
            {
                --r;
            }
        }
        return nums[l];
    }
};
// @lc code=end

