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
#if 1   // 贪心
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
#endif

#if 0   // 自己写的
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 负例
        if (intervals.size() <= 1)
            return intervals;

        // 按左边界升序排序
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) -> bool {
            return a[0] < b[0];
        });

        int left = intervals[0][0], right = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); ++i)
        {
            // 重叠区间
            if (intervals[i][0] <= right)
            {
                // 这里必须要  max
                right = max(right, intervals[i][1]);
            }
            // 新的区间
            else if (intervals[i][0] > right)
            {
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            
            // 添加最后一个区间
            if (i == intervals.size() - 1)
                res.push_back({left, right});
        }

        return res;
    }

#endif
};
// @lc code=end

