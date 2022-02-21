/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
/** 
 * 数组，前缀和
 * 定义：preSum[i][j] 记录 matrix 中子矩阵 [0, 0, i-1, j-1] 的元素和
 */
#include <vector>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> pre_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        // 分配内存
        int m = matrix.size(), n = matrix[0].size();
        pre_sum.resize(m + 1, vector<int>(n + 1));
        // 计算积分图
        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                pre_sum[i][j] = pre_sum[i-1][j] + pre_sum[i][j-1] 
                                - pre_sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre_sum[row2+1][col2+1] + pre_sum[row1][col1] 
                - pre_sum[row2+1][col1] - pre_sum[row1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

