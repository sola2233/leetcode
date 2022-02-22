/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
/** 
 * 镜像+反转
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 镜像
        for (int i = 0; i < m; ++i)
        {
            for (int j = i; j < n; ++j)
                // 交换，成镜像
                swap(matrix[i][j], matrix[j][i]);
        }

        // 反转每一行
        for (auto& row : matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};
// @lc code=end

