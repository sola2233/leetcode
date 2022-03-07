/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
/** 
 * 方法1.回溯法，会超时
 * 方法2.动态规划，完全背包
 */
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
class Solution {
public:
    // 回溯法
    // int res;
    // int sum;
    // int combinationSum4(vector<int>& nums, int target) {
    //     res = 0;
    //     sum = 0;
    //     sort(nums.begin(), nums.end());
    //     backtracking(nums, target, 0);
    //     return res;
    // }

    // void backtracking(vector<int>& nums, int target, int start_idx)
    // {
    //     // 剪枝
    //     if (sum > target)
    //         return;
    //     // 终止条件
    //     if (sum == target)
    //     {
    //         res++;
    //         return;
    //     }

    //     // 在本层做选择，从下标 0 开始，因为顺序不同的序列视作不同组合，选择范围为整个 nums
    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         // 本层剪枝
    //         if (sum + nums[i] > target)
    //             break;
    //         sum += nums[i];
    //         backtracking(nums, target, i); // 不用加 1，表示可以重复选择
    //         sum -= nums[i];
    //     }
    // }

    /** 
     * 完全背包
     * dp[j]: 总和为 j 的组合数为 dp[j]
     * 状态转移: dp[j] += dp[j - nums[i]]
     * base case: dp[0] = 1
     */
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        // base case
        dp[0] = 1;
        // 遍历背包，本题是求排列数，所以遍历顺序要改，先背包再物品
        for (int i = 0; i <= target; ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
                // C++测试用例有超过两个树相加超过int的数据，所以需要在if里加上dp[i] < INT_MAX - dp[i - num]
                if (i >= nums[j] && dp[i] < INT32_MAX - dp[i - nums[j]])
                    dp[i] += dp[i - nums[j]];
        }
        return dp[target];
    }
};
// @lc code=end

