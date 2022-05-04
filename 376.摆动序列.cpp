/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
/** 
 * 方法1.贪心 o(n)
 * 方法2.动态规划，o(n^2)
 * 方法3.动态规划，o(n)
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
#if 0   // 方法1.贪心，记录峰值的数量，单调坡上的元素就是要删掉的元素
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int pre_diff = 0, cur_diff = 0;
        int res = 1; // 第一个元素默认添加
        for (int i = 1; i < nums.size(); ++i)
        {
            cur_diff = nums[i] - nums[i - 1];
            // 出现摆动，即峰和谷，pre_diff 等于 0 并不重要，只要 cur_diff 变化了，就说明出现了摆动
            if ((cur_diff > 0 && pre_diff <= 0) || (cur_diff < 0 && pre_diff >= 0))
            {
                ++res;
                // note 为什么这句话不能放在外面
                pre_diff = cur_diff;
            }
        }

        return res;
    }
#endif


#if 0   // 方法2.动态规划，o(n^2)
    int wiggleMaxLength(vector<int>& nums) {
        // dp(i) : 以 nums[i] 结尾的最长摆动序列长度
        vector<int> dp1(nums.size(), 1);    // 上升摆动序列
        vector<int> dp2(nums.size(), 1);    // 下降摆动序列


        int max_cnt = 0;    // 计数
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                    dp1[i] = max(dp1[i], dp2[j] + 1);
                if (nums[i] < nums[j])
                    dp2[i] = max(dp2[i], dp1[j] + 1);
            }
            max_cnt = max({max_cnt, dp1[i], dp2[i]});
        }

        return max_cnt;
    }
#endif


#if 1   // 方法3.动态规划，o(n)
        // 解释见评论https://leetcode-cn.com/problems/wiggle-subsequence/solution/bai-dong-xu-lie-by-leetcode-solution-yh2m/
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // 也可以用 up 和 down 两个数组
        // dp[i][0] [0, i] 中，最长上升摆动子序列的最长长度
        // dp[i][1] [0, i] 中，最长下降摆动子序列的最长长度
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
#endif
};
// @lc code=end

