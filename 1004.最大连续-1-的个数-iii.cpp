/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
/** 
 * 滑动窗口，统计窗口中 0 的个数
 */
#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // 计数窗口中 0 的数目
        int sum = 0;
        // 左闭右开
        int left = 0, right = 0;
        int res = 0; // 连续 1 的最大个数
        while (right < nums.size())
        {
            if (nums[right] == 0)
                sum++;
            // 扩大窗口
            right++;
            // 更新结果，注意 sum 不一定会大于 k，所以要在这里更新结果，不能在收缩时更新
            if (sum <= k)
                res = max(res, right - left);
            // 缩小窗口条件
            while (sum > k)
            {
                // 删的是 0 的话计数减一
                if (nums[left] == 0)
                    sum--;
                // 收缩窗口
                left++;
            }
        }

        return res;
    }
};
// @lc code=end

