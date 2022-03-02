/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
/** 
 * 方法1.贪心 o(n)
 * 方法2.动态规划
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 方法1.贪心，记录峰值的数量，单调坡上的元素就是要删掉的元素
    // int wiggleMaxLength(vector<int>& nums) {
    //     if (nums.size() == 1)
    //         return 1;
    //     int pre_diff = 0, cur_diff = 0;
    //     int res = 1; // 第一个元素默认添加
    //     for (int i = 1; i < nums.size(); ++i)
    //     {
    //         cur_diff = nums[i] - nums[i - 1];
    //         // 出现摆动，即峰和谷，pre_diff 等于 0 的情况只会出现在开头
    //         if ((cur_diff > 0 && pre_diff <= 0) || (cur_diff < 0 && pre_diff >= 0))
    //         {
    //             ++res;
    //             pre_diff = cur_diff;
    //         }
    //     }

    //     return res;
    // }

    // 方法2.动态规划
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // 也可以用 up 和 down 两个数组
        // dp[i][0] [0, i] 中，第i个数作为山峰的摆动子序列的最长长度
        // dp[i][1] [0, i] 中，第i个数作为山谷的摆动子序列的最长长度
        vector<vector<int>> dp(n, vector<int>(2));
        // base case
        dp[0][0] = dp[0][1] = 1;
        // 遍历
        for (int i = 1; i < n; ++i)
        {
            // 状态转移
            if (nums[i] > nums[i - 1])
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = dp[i - 1][1];
            }
            else if (nums[i] < nums[i - 1])
            {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + 1);
            }
            else if (nums[i] == nums[i - 1])
            {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            }
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
// @lc code=end

