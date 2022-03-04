/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
/** 
 * 贪心，区间调度问题
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * 贪心思想，最优情况下每只箭都射在某个气球的右边界 
     */
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        // 按区间右边界升序排序
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 1; // 计数，至少有一个不想交区间
        int pre_end = points[0][1]; // 区间右边界
        // 遍历区间
        for(int i = 0; i < n; i++)
        {
            // 区间重叠
            if(points[i][0] <= pre_end)
                continue;
            // 区间不重叠时，更新右边界，计数加 1
            else 
            {
                pre_end = points[i][1];
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

