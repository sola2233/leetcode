/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
/** 
 * 动态规划，有点像 1143 最长公共子序列
 */
#include <vector>
using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // base case
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end

