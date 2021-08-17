/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /** 负例，空的向量 */
        if(intervals.empty())
            return 0;
        /** 对输入的区间按右边界从小到大排序 */
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; /* note lambda输入参数要是引用 */
        });
        /** 删除的区间数量 */
        int removedNums = 0;
        /** 前一个区间右边界的值 */
        int prev = intervals[0][1];
        /** 从第二个区间开始处理 */
        for(int i = 1; i < intervals.size(); i++)
        {
            /** 判断相邻的下一个区间是否和前一个区间重叠 */
            if(intervals[i][0] < prev)
                removedNums++;
            /** 不重叠则更新前一个区间右边界的值 */
            else
                prev = intervals[i][1];
        }
        return removedNums;
    }
};
// @lc code=end

