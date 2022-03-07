/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i][j]: 以 i j 为下标的 A[0,i] 和 B[0, j] 的最长子数组长度
 */
#include <vector>
using namespace std;
class Solution {
public:
    // 可以继续优化空间复杂度，减少一维
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // base case，初始化为 0，这里大小都加了 1，为了便于处理循环，方便一点
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int res = 0;
        // 两种遍历顺序都可以
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end

