/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
/** 
 * 排序+滑动窗口
 * 回溯法不行，可能复杂度太高
 */
#include <vector>
#include <stdint.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // 排序，选择的 k 个元素必是有序数组中连续的 k 个
        sort(nums.begin(), nums.end());
        // 滑动窗口，左闭右开
        int n = nums.size();
        int left = 0, right = 0;
        int res = INT32_MAX;
        while (right < n)
        {
            int num_max = nums[right];
            // 窗口扩大
            right++;

            // 窗口缩小条件
            if (right - left == k)
            {
                int num_min = nums[left];
                // 窗口缩小
                left++;
                // 更新结果
                res = min(res, num_max - num_min);
            }
        }

        return res;
    }
};
// @lc code=end

