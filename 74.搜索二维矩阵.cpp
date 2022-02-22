/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
/** 
 * 二分搜索
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int upper = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        // 列二分搜索
        while (upper <= bottom)
        {
            int mid = upper + (bottom - upper) / 2;
            if (matrix[mid][0] < target)
                upper = mid + 1;
            else if (matrix[mid][0] > target)
                bottom = mid - 1;
            else if (matrix[mid][0] == target)
                return true;
        }
        // 检查越界，为什么是 bottom 呢，因为最后一定 upper == bottom == mid
        // 无论 mid 对应的数大于还是小于 target，bottom 对应的数都小于 target
        if (bottom < 0 || bottom >= m)
            return false;
        // 行二分搜索
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[bottom][mid] < target)
                left = mid + 1;
            else if (matrix[bottom][mid] > target)
                right = mid - 1;
            else if (matrix[bottom][mid] == target)
                return true;
        }

        return false;
    }
};
// @lc code=end

