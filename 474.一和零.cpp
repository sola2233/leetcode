/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
/** 
 * 动态规划
 * 二维 01 背包问题，相当于有两个背包，一个容量为 m，一个容量为 n
 * 不同长度的字符串就是不同大小的待装物品。
 * dp[i][j]：最多有 i 个 0 和 j 个 1 的 strs 的最大子集的大小为 dp[i][j]
 * dp[i][j] 可以由前一个 str 里的字符串推导出来，str 里的字符串有zeroNum个0，oneNum个1。
 * 递推公式：dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
 * 对比一下就会发现，字符串的zeroNum和oneNum相当于物品的重量（weight[i]）
 * 字符串本身的个数相当于物品的价值（value[i]）。
 * base case：01背包的dp数组初始化为0就可以，含义就是 0 个 0 和 0 个 1 的自己大小为 0
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:

#if 1   // 空间压缩
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // base case
        dp[0][0] = 0;
        // 遍历物品
        for (auto& str : strs)
        {
            // 计算 0 和 1 的个数
            int num_zero = 0, num_one = 0;
            for (auto& ch : str)
            {
                if (ch == '0') num_zero++;
                else num_one++;
            }
            // 遍历背包，从后往前遍历
            for (int i = m; i >= num_zero; --i)
            {
                for (int j = n; j >= num_one; --j)
                    dp[i][j] = max(dp[i][j], dp[i - num_zero][j - num_one] + 1);
            }
        }
        return dp[m][n];
    }
#endif


#if 0   // 空间复杂度较高
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<int> zero(size, 0);
        vector<int> one(size, 0);
        // 计数
        for (int i = 0; i < size; ++i)
        {
            for (char &ch : strs[i])
            {
                if (ch == '0')
                    zero[i]++;
                else
                    one[i]++;
            }
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // base case
        dp[0][0] = 0;
        // 遍历物品
        for (int i = 0; i < size; ++i)
        {
            // 遍历背包，从后往前遍历
            for (int j = m; j >= zero[i]; --j)
            {
                for (int k = n; k >= one[i]; --k)
                {
                    dp[j][k] = max(dp[j - zero[i]][k - one[i]] + 1, dp[j][k]);
                }
            }
        }

        return dp[m][n];
    }
#endif
};
// @lc code=end

