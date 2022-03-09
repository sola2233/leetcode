/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
/** 
 * 方法1.动态规划，二维，但是要遍历两次，左上到右下，右下到左上
 * 方法2.bfs + 备忘录
 */
#include <vector>
#include <cstdint>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // base case
        vector<vector<int>> dp(m, vector<int>(n, 100000));
        // 遍历
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                else if (mat[i][j] == 1)
                {
                    // 要和自己比，和上面比，和左边比，分两次比较
                    if (i > 0) // 和上面比
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (j > 0) // 和左边比
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        // 遍历
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (mat[i][j] != 0)
                {
                    // 要和自己比，和下面比，和右边比，分两次比较
                    if (i < m - 1) // 和下边比
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    if (j < n - 1) // 和右边比
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);                    
                }
            }
        }
        return dp;
    }

};
// @lc code=end

