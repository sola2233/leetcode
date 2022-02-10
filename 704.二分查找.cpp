/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
/** 
 * 二分搜索问题，常用左闭右开，逻辑统一可以左闭右闭
 */
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 左闭右闭
        int left = 0, right = nums.size()-1;

        // [left, right]，看出循环终止条件
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] == target)
                return mid; // 找到直接返回
        }

        // 跳出循环就是没找到
        return -1;
    }
};
// @lc code=end

