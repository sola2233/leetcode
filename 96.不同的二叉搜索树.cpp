/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
/** 
 * bst
 * 方法1.递归函数，带备忘录
 * 方法2.动态规划
 */
#include <vector>
using namespace std;
class Solution {
public:

#if 0   // labuladong的一大坨代码
    
    vector<vector<int>> memo;
    int numTrees(int n) {
        // 初始化备忘录
        memo = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        
        int res = count(1, n);

        return res;
    }

    // 递归函数，返回 [lo, hi] 区间组成的互不相同 bst 个数
    int count(int lo, int hi)
    {
        // base case，区间为空，也是一种情况
        if (lo > hi)
            return 1;
        
        // 查询备忘录，解决重叠子区间
        if (memo[lo][hi] != 0)
            return memo[lo][hi];

        // 递归，固定 i 为 root，递归得到左右子树个数，两者乘积就是 i 为 root 的不同 bst 个数
        int sum = 0;
        for (int i = lo; i <= hi; ++i)
        {
            int left = count(lo, i - 1);
            int right = count(i + 1, hi);
            sum += left * right;
        }
        // 结果存入备忘录
        memo[lo][hi] = sum;

        return sum;
    }
#endif


#if 0   // 方法1.递归子树 
    
    bool start = true;
    vector<int> memo;
    int numTrees(int n) {
        if (start)
        {
            memo.resize(n + 1);
            start = false;
        }
        // base case
        if (n <= 1) return 1;
        // 查备忘录
        if (memo[n] != 0)
            return memo[n];
        // 递归子树
        int sum = 0;
        for (int i = 0; i <= n - 1; ++i)
        {
            int left = numTrees(i);
            int right = numTrees(n - 1 - i);
            sum += left * right;
        }
        memo[n] = sum;
        return sum;
    }
#endif


#if 1   // 方法2.动态规划，时间复杂度 o(n^2)，空间复杂度 o(n)

    int numTrees(int n) {
        vector<int> dp(n + 1);
        // base case
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            // 去掉一个根节点，只剩 i - 1 个节点
            for (int j = 0; j <= i - 1; ++j)
                dp[i] += dp[j] * dp[i - 1 - j];
        }
        return dp[n];
    }
#endif
};
// @lc code=end

