/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        // 四个边界
        int upper_bound = 0, bottom_bound = n - 1;
        int left_bound = 0, right_bound = n - 1;

        // 转圈遍历填充数组
        int num = 1, sz = n * n;
        while (num <= sz)
        {
            // 向右
            if (upper_bound <= bottom_bound)
            {
                for (int j = left_bound; j <= right_bound; ++j)
                    res[upper_bound][j] = num++;
                ++upper_bound;
            }

            // 向下
            if (left_bound <= right_bound)
            {
                for (int i = upper_bound; i <= bottom_bound; ++i)
                    res[i][right_bound] = num++;
                --right_bound;
            }

            // 向左
            if (upper_bound <= bottom_bound)
            {
                for (int j = right_bound; j >= left_bound; --j)
                    res[bottom_bound][j] = num++;
                --bottom_bound;
            }

            // 向上
            if (left_bound <= right_bound)
            {
                for (int i = bottom_bound; i >= upper_bound; --i)
                    res[i][left_bound] = num++;
                ++left_bound;
            }
        }

        return res;
    }
};
// @lc code=end

