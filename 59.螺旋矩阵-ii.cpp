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

        // 左闭右闭，转圈遍历填充数组
        int num = 1, sz = n * n;
        while (num <= sz)
        {
            if (upper_bound <= bottom_bound)
            {
                // 在顶部从左向右遍历
                for (int j = left_bound; j <= right_bound; ++j)
                    res[upper_bound][j] = num++;
                // 上边界下移
                ++upper_bound;
            }

            if (left_bound <= right_bound)
            {
                // 在右侧从上向下遍历
                for (int i = upper_bound; i <= bottom_bound; ++i)
                    res[i][right_bound] = num++;
                // 右边界左移
                --right_bound;
            }

            if (upper_bound <= bottom_bound)
            {
                // 在底部从右向左遍历
                for (int j = right_bound; j >= left_bound; --j)
                    res[bottom_bound][j] = num++;
                // 下边界上移
                --bottom_bound;
            }

            if (left_bound <= right_bound)
            {
                // 在左侧从下向上遍历
                for (int i = bottom_bound; i >= upper_bound; --i)
                    res[i][left_bound] = num++;
                // 左边界右移
                ++left_bound;
            }
        }

        return res;
    }
};
// @lc code=end

