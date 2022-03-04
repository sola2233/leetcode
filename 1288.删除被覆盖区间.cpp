/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start
/** 
 * 贪心
 * 拍完序 start 就是递增的了，后面的区间 start 一定被前面区间的 start 包含
 * 所以只要比较区间的 end
 * 算法中找重叠区间个数，最后 n - count 就是剩余区间数目
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // 排序，按 start 递增，start 相同按 end 递减
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) -> bool {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        // 遍历区间
        int end = intervals[0][1];
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            // 情况1.找到重叠区间
            if (intervals[i][1] <= end)
                res++;
            // 情况 2 3 合并
            else
                end = intervals[i][1];
            // 情况2.两个区间有重叠部分
            // else if (intervals[i][0] <= end && intervals[i][1] > end)
                // end = intervals[i][1];
            // 情况3.不重叠
            // else if (intervals[i][0] > end)
                // end = intervals[i][1];
        }

        return n - res;
    }
};
// @lc code=end

