/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
/** 
 * 二分查找
 * 待改进：可以用mid的值代替is_odd
 */
#include <vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        /** 这里是小于号，相等时区间只剩一个元素，即要找的单元素 */
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            /** 判断哪一侧数组个数是否是奇数 */
            int is_odd = (r - mid + 1) % 2;
            /** 中间元素的同一元素在右边 */
            if (nums[mid] == nums[mid + 1])
            {
                /** 右侧是奇数 */
                if (is_odd)
                {
                    l = mid + 2;
                }
                /** 左侧是奇数 */
                else
                {
                    r = mid - 1;
                }
            }
            /** 中间元素的同一元素在左边 */
            else if (nums[mid] == nums[mid - 1])
            {
                /** 左侧是奇数 */
                if (is_odd)
                {
                    r = mid - 2;
                }
                /** 右侧是奇数 */
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return nums[l];
    }
};
// @lc code=end

