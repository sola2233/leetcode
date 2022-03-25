/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
/** 
 * 剑指 offer 面试题 4
 * 从右上角开始比较，复杂度 o(m + n)，因为循环中就是移动 i 和 j，i 和 j 总共移动 m + n 次
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            // 向左移动一列
            if (matrix[i][j] > target)
                j--;
            // 向下移动一行
            else if (matrix[i][j] < target)
                i++;
            else if (matrix[i][j] == target)
                return true;
        }
        return false;
    }
};
// @lc code=end

