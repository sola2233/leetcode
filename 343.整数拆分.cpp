/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
/** 
 * 动态规划
 * dp[i]: 正整数 i 拆分后的最大乘积
 * 状态转移: dp[i] = max(dp[i - j], i - j) * max(dp[j], j)
 *         (j = 1, 2, 3, 4, ..., i / 2)
 *         含义就是把 i 拆分，在所有可能中找最大的：
 *         拆分两个就是 j, i - j
 *         拆分一个和多个就是 j, dp[i - j] 或者 dp[j], i - j
 *         拆分更多就是 dp[j] dp[i - j]
 * base case: dp[1] = 1，dp[2] = 1，dp[3] = 2，dp[4] = 4，dp[5] = 6
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

#if 0   // 复杂一点的写法
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            // 和答案思想是一样的，只是他们这里遍历范围是 i，所以和我的其实是一样的
            for (int j = 1; j <= i / 2; ++j)
            {
                int num1 = max(dp[j], j);
                int num2 = max(dp[i - j], i - j);
                dp[i] = max(dp[i], num1 * num2);
            }
        }

        return dp[n];
    }
#endif

#if 1   // 更简单的写法
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        // base case
        dp[2] = 1;
        
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j <= i - 1; ++j)
            {
                // note 为什么 j 不用差分
                dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
            }
        }

        return dp[n];
    }
#endif
};
// @lc code=end

