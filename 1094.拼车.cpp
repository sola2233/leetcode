/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
/** 
 * 差分数组
 * 构造差分数组，只要原数组中没有一站超过 capacity 就不会超载
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 构造差分数组
        vector<int> diff(1001); // 题目最大 1001 站
        for (auto& trip : trips)
        {
            int first = trip[1];
            int last = trip[2] - 1; // 注意要减一，因为当前站已经下车了
            diff[first] += trip[0];
            if (last + 1 < 1001)
                diff[last + 1] -= trip[0];
        }

        // 还原数组并判断是否超载
        for (int i = 0; i < 1001; ++i)
        {
            // i == 0 时当前站就是 diff[i] 人
            if (i > 0)
                diff[i] += diff[i-1];
            // 判断是否超载
            if (diff[i] > capacity)
                return false;
        }

        return true;
    }
};
// @lc code=end

