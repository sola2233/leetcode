/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
/** 
 * 方法1.暴力法，o(n^3)
 * 方法2.动态规划，o(n^2)，看 carl
 * dp[i][j]: s[i,j] 子串是否是回文
 * 状态转移: if (s[i] != s[j]) dp[i][j] = false
 *          相等时，1.if (i == j) dp[i][j] = true
 *                 2.if (j - i == 1) dp[i][j] = true
 *                 3.if (dp[i+1][j-1]) dp[i][j] = true
 * base case: 初始化为 false
 * 遍历顺序: 从下往上，从左往右遍历
 * 方法3.双指针法，o(n^2)，空间 o(1)
 * 遍历字符串，找中心往两边扩散，边扩散边判断是不是回文
 * 扩散有两种：1.一个元素可以作为中心点
 *           2.两个元素也可以作为中心点
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        // base case
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int res = 0; // 记录回文串个数
        // 从下往上
        for (int i = n - 1; i >= 0; i--)
        {
            // 从左往右
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    // 相等或者下标相差大于 1
                    if (j - i <= 1)
                    {
                        dp[i][j] = true;
                        res++;
                    }
                    else if (dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

