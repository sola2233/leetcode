/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
/** 
 * 贪心
 * 那么我按照左边界排序，排序之后局部最优：每次合并都取最大的右边界
 * 这样就可以合并更多的区间了，整体最优：合并所有重叠的区间。
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        // 排序，按区间起点 start 升序排序
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) -> bool {
            return a[0] < b[0];
        });

        // 遍历区间
        int start = 0, end = 0;
        for (int i = 0; i < n;) 
        {
            start = intervals[i][0]; // 左边界
            end = max(end, intervals[i][1]); // 右边界
            // 找重叠区间，相等也算，不断更新右边界
            while (i < n && intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
                ++i;
            }
            // 合并完一个重叠区间
            res.push_back(vector<int>{start, end});
        }

        return res;
    }
};
// @lc code=end

