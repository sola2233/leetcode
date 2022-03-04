/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
/** 
 * 贪心，记录每次能达到的最大范围
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 记录当前可以跳的最大范围，不断更新
        int cover = 0;
        // 遍历
        for (int i = 0; i <= cover; ++i)
        {
            // 更新跳的范围
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1)
                return true;
        }

        return false;
    }
};
// @lc code=end

