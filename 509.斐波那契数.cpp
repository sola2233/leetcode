/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
/** 
 * 类似动态规划
 */
class Solution {
public:
    int fib(int n) {
        // base case
        if (n == 0 || n == 1)
            return n;

        // 自底向上，遍历所有状态，此处还用了空间压缩
        int pre2 = 0, pre1 = 1, cur = 0;
        for (int i = 2; i <= n; ++i)
        {
            cur = pre2 + pre1;
            pre2 = pre1;
            pre1 = cur;
        }

        return cur;
    }
};
// @lc code=end

