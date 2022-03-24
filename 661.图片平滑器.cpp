/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
/** 
 * 时间复杂度 o(m*n)
 * 方法1.前缀和，基于列和 col_sum
 * 方法2.前缀和，基于积分图
 */
#include <vector>
using namespace std;
class Solution {
public:
    // 方法1.列和
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        // 计算列和
        vector<int> col_sum(n, 0);
        for (int j = 0; j < n; ++j)
            col_sum[j] += img[0][j];

        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            // 重新计算列和
            for (int j = 0; j < n; ++j)
            {
                if (i - 2 >= 0)
                    col_sum[j] -= img[i - 2][j];
                if (i + 1 <= m - 1)
                    col_sum[j] += img[i + 1][j];
            }
            // 图像平滑
            for (int j = 0; j < n; ++j)
            {
                int sum = col_sum[j];
                if (j - 1 >= 0)
                    sum += col_sum[j - 1];
                if (j + 1 <= n - 1)
                    sum += col_sum[j + 1];
                res[i][j] = sum / getSum(i, j, m, n);
            }
        }
        return res;
    }

    // 计算 (x, y) 的九宫格有几个有效
    int getSum(int x, int y, int m, int n)
    {
        int x_min = max(0, x - 1);
        int y_min = max(0, y - 1);
        int x_max = min(m - 1, x + 1);
        int y_max = min(n - 1, y + 1);
        return (x_max - x_min + 1) * (y_max - y_min + 1);
    }
};
// @lc code=end

