/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * 贪心思想，最优情况下每只箭都射在某个气球的右边界 
     */
    int findMinArrowShots(vector<vector<int>>& points) {
        int size = points.size();
        /** 没有气球或只有一个 */
        if(size < 2)
            return size;
        /** 按区间右边界升序排序 */
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        /** 箭计数 */
        int count(1);
        /** 保存前一个区间右边界 */
        int preR = points[0][1];
        for(int i=1; i < size; i++)
        {
            /** 区间重叠则跳过，只需要一支箭 */
            if(points[i][0] <= preR)
                continue;
            /** 区间不重叠，需要增加一支箭 */
            else 
            {
                preR = points[i][1];
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

