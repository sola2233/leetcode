/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
/** 
 * 动态规划问题
 * 思考流程：明确 base case -> 明确「状态」-> 明确「选择」 -> 定义 dp 数组/函数的含义
 * 1.base case：一间房子就是房子金额，两间就取最大
 * 2.状态：就是房子数目 n
 * 3.选择：房子数目增加
 * 4.dp(n)：给定n个房子，求能偷到最大金额，dp(i) 表示抢劫到第 i 个房子时，可以抢劫的最大数量
 */
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
class Solution {
public:
    // 方法3：方法2基础上空间压缩
    int rob(vector<int>& nums) {
        int n = nums.size();
        // base case
        if (n == 1)
            return nums[0];
        // 自底向上
        int pre2 = 0, pre1 = 0, cur = 0;
        for (int i = 1; i <= n; ++i)
        {
            cur = max(pre2+nums[i-1], pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }

    // 方法2：dp数组，自底向上
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     // 数组大小 n+1，初值为0
    //     vector<int> dp(n+1, 0);
    //     // base case
    //     dp[1] = nums[0];
    //     // 自底向上
    //     for (int i = 2; i <= n; ++i)
    //     {
    //         dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
    //     }
    //     return dp[n];
    // }

    // 方法1：带备忘录的递归，消除重叠子问题，自顶向下
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     // 备忘录，加1是由于dp的定义
    //     vector<int> memo(n+1, -1);

    //     return dp(nums, n, memo);
    // }

    // int dp(vector<int>& nums, int n, vector<int>& memo)
    // {
    //     // base case
    //     if (n == 1)
    //         return nums[0];
    //     if (n == 2)
    //         return max(nums[0], nums[1]);
    //     // 查备忘录，防止重复计算
    //     if (memo[n] != -1)
    //         return memo[n];
    //     // 计算子问题，并且选择最优解，状态转移方程
    //     memo[n] = max(dp(nums, n-2, memo) + nums[n-1], dp(nums, n-1, memo));

    //     return memo[n];
    // }
};
// @lc code=end

