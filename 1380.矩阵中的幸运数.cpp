/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
#include <vector>
#include <cstdint>
using namespace std;
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        // 预处理，找出每行最小值和每列最大值
        vector<int> min_row(m, INT32_MAX), max_col(n, 0);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                min_row[i] = min(min_row[i], matrix[i][j]);
                max_col[j] = max(max_col[j], matrix[i][j]);
            }
        }

        // 遍历一遍 matrix
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == min_row[i] && matrix[i][j] == max_col[j])
                    res.push_back(matrix[i][j]);
        }

        return res;
    }
};
// @lc code=end

