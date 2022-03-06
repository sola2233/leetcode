/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start
/** 
 * 动态规划

 */
#include <vector>
using namespace std;
class Solution {
public:
    // 一大坨代码，过了140个case，舍不得删
    // dp[i]: 第 i 天是不是打劫的日子，状态转移: dp[i] = 
    // vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    //     int n = security.size();
    //     vector<int> res;
    //     vector<bool> dp(n);
    //     // 负例
    //     if (time == 0)
    //     {
    //         for (int i = 0; i < n; ++i) res.push_back(i);
    //         return res;
    //     }
    //     // base case
    //     int count = 0;
    //     for (int i = 0; i <= time; ++i)
    //     {
    //         if (count < time && i - 1 >= 0 && i + time < n
    //             && security[i] <= security[i - 1]
    //             && security[i + time] >= security[i + time - 1])
    //         {
    //             count++;
    //         }
    //         if (count == time)
    //         {
    //             dp[time] = true;
    //             res.push_back(time);
    //             count = 0;
    //         }
    //     }

    //     for (int i = time + 1; i < n; ++i)
    //     {
    //         if (dp[i - 1]
    //             && security[i] <= security[i - 1]
    //             && security[i + time] >= security[i + time - 1])
    //         {
    //             dp[i] = 1;
    //             res.push_back(i);
    //         }
    //         else if (!dp[i - 1])
    //         {
    //             if (count < time && i - 1 >= 0 && i + time < n
    //                 && security[i] <= security[i - 1]
    //                 && security[i + time] >= security[i + time - 1])
    //                 count++;
    //             if (count == time)
    //             {
    //                 dp[i] = true;
    //                 res.push_back(i);
    //                 count = 0;
    //             }
    //         }
    //     }

    //     return res;
    // }

    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> left(n);
        vector<int> right(n);
        // left[i]: 第 i 天前连续递减天数，包括第 i 天
        // right[i]: 第 i 天后连续递增天数，包括第 i 天
        for (int i = 1; i < n; i++)
        {
            // 满足条件就加 1，否则置 0，因为已经初始化为 0，所以不用做什么了
            if (security[i] <= security[i - 1])
                left[i] = left[i - 1] + 1;
            if (security[n - i - 1] <= security[n - i])
                right[n - i - 1] = right[n - i] + 1;
        }

        vector<int> ans;
        for (int i = time; i < n - time; i++)
        {
            if (left[i] >= time && right[i] >= time)
                ans.emplace_back(i);
        }
        return ans;
    }

};
// @lc code=end

