/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
/** 
 * 贪心，区间调度，类似 452 气球
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // 排序
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 1; // 记录不重叠区间个数，同 452
        int pre_end = intervals[0][1];
        // 遍历区间
        for(int i = 0; i < n; i++)
        {
            // 区间重叠
            if(intervals[i][0] < pre_end)
                continue;
            // 区间不重叠
            else
            {
                pre_end = intervals[i][1];
                count++;
            }
        }
        return n - count;
    }
};
// @lc code=end

