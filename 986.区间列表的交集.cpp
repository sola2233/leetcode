/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
/** 
 * 贪心，双指针遍历两个区间列表，要把所有情况分析好
 * 感觉像个模拟题
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        // 遍历
        int n = firstList.size(), m = secondList.size();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            // A 和 B 的区间
            int a_start = firstList[i][0], a_end = firstList[i][1];
            int b_start = secondList[j][0], b_end = secondList[j][1];
            // 如果有相交区间
            if (a_end >= b_start && b_end >= a_start)
            {
                // 计算相交区间
                int start = max(a_start, b_start);
                int end = min(a_end, b_end);
                res.push_back(vector<int>{start, end});
            }
            // 递增指针
            if (a_end > b_end)
                j++;
            else if (a_end <= b_end)
                i++;
        }

        return res;
    }
};
// @lc code=end

