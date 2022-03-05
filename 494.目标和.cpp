/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
/** 
 * 方法1.回溯法
 * 方法2.动态规划，转化为 01 背包问题
 * 假设分成两堆，left 是 +，right 是 -，则 left - right = target
 * 又 sum = left + right，得到 left - (sum - left) = target
 * 即 left = (target + sum) / 2
 * 所以问题转化为，能找到多少和为 (target + sum) / 2 的子集
 * 本题还是有点难度，大家也可以记住，在求装满背包有几种方法的情况下，递推公式一般为：
 * dp[j] += dp[j - nums[i]];
 */
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 二维
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 负例
        if ((target + sum) % 2 == 1)
            return 0;
        if (abs(target) > sum) // target 可能为负数
            return 0;
        
        int bag_size = (target + sum) / 2;
        // dp[i][j]：使用 下标为[0, i]的nums[i]能够凑满j（包括j）这么大容量的包，有dp[i][j]种方法
        vector<vector<int>> dp(n, vector<int>(bag_size + 1, 0));
        // base case
        dp[0][0] = 1;
        if (nums[0] > 0 && nums[0] <= bag_size)
            dp[0][nums[0]] = 1;
        else if (nums[0] == 0) // nums[0] 可能为 0，太tm麻烦了
            dp[0][nums[0]] = dp[0][0] + 1;
        // 遍历物品
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= bag_size; ++j)
            {
                if (j < nums[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
            }
        }
        return dp[n - 1][bag_size];
    }

    // 一维
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     // 负例
    //     if ((target + sum) % 2 == 1)
    //         return 0;
    //     if (abs(target) > sum) // target 可能为负数
    //         return 0;
        
    //     int bag_size = (target + sum) / 2;
    //     // dp[j] 表示：填满j（包括j）这么大容积的包，有dp[j]种方法
    //     vector<int> dp(bag_size + 1, 0);
    //     dp[0] = 1;
    //     for (int i = 0; i < n; ++i)
    //     {
    //         for (int j = bag_size; j >= nums[i]; --j)
    //         {
    //             dp[j] += dp[j - nums[i]];
    //         }
    //     }
    //     return dp[bag_size];
    // }
};
// @lc code=end

