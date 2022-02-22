/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        // 四个边界
        int upper_bound = 0, bottom_bound = m - 1;
        int left_bound = 0, right_bound = n - 1;

        // 遍历数组
        int sz = m * n;
        while (res.size() < sz)
        {
            // 向右
            if (upper_bound <= bottom_bound)
            {
                for (int j = left_bound; j <= right_bound; ++j)
                    res.push_back(matrix[upper_bound][j]);
                ++upper_bound;
            }

            // 向下
            if (left_bound <= right_bound)
            {
                for (int i = upper_bound; i <= bottom_bound; ++i)
                    res.push_back(matrix[i][right_bound]);
                --right_bound;
            }

            // 向左
            if (upper_bound <= bottom_bound)
            {
                for (int j = right_bound; j >= left_bound; --j)
                    res.push_back(matrix[bottom_bound][j]);
                --bottom_bound;
            }

            // 向上
            if (left_bound <= right_bound)
            {
                for (int i = bottom_bound; i >= upper_bound; --i)
                    res.push_back(matrix[i][left_bound]);
                ++left_bound;
            }
        }

        return res;
    }
};
// @lc code=end

