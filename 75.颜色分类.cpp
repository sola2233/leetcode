/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
/** 
 * 双指针排序
 * 参考https://leetcode-cn.com/problems/sort-colors/solution/yan-se-fen-lei-by-leetcode-solution/
 * 指针 p0 交换 0， 指针 p2 交换 2，
 * 遍历一遍，找出所有 0 交换到数组头部，找出所有 2 交换到数组尾部
 * 同时，交换完 nums[i] 依然有可能是 2 或者 0
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * 排序0，1，2 
     * @param 带排序数组
     */
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (size < 2)
            return;
        
        // 0 [0, p0)
        // 1 [p0, p2] 交换过程中可能为 0，1，2
        // 2 (p2, size)

        int p0 = 0, p2 = size - 1;
        // 遍历整个数组，这里i可以等于 p2，防止最后 p2 为0
        for (int i = 0; i <= p2; ++i)
        {
            // 重复将 2 和 p2 交换，但是 p2 可能是 2 或者 0
            while (i <= p2 && nums[i] == 2)
            {
                swap(nums[i], nums[p2]);
                --p2;
            }
            // 如果 nums[i] 为 0，和p0交换，p0 一定是 1
            if (nums[i] == 0)
            {
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};
// @lc code=end

