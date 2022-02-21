/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
/** 
 * 差分数组
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 构造差分数组
        vector<int> diff(n);
        for (auto& booking : bookings)
        {
            int first = booking[0] - 1;
            int last = booking[1] - 1;
            int val = booking[2];
            diff[first] += val;
            if (last + 1 < n)
                diff[last + 1] -= val;
        }

        // 还原数组，不用分配新空间
        for (int i = 1; i < n; ++i)
            diff[i] += diff[i - 1];

        return diff;
    }
};
// @lc code=end

