/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
/** 
 * 经典动态规划问题
 * 定义一个数组 dp，dp[i] 表示走到第 i 阶的方法数。
 * 因为我们每次可以走一步或者两步，所以第 i 阶可以从第 i-1 或 i-2 阶到达。
 * 换句话说，走到第 i 阶的方法数即为走到第 i-1 阶的方法数加上走到第 i-2 阶的方法数。
 * 这样我们就得到了状态转移方程dp[i] = dp[i-1] + dp[i-2]
 */
class Solution {
public:
    int climbStairs(int n) {
        // 为了压缩空间，不用数组
        if (n <= 2)
            return n;

        int a = 1, b = 2, cur;
        for (int i = 3; i <= n; ++i)
        {
            cur = a + b;
            a = b;
            b = cur;
        }

        return cur;
    }
};
// @lc code=end

