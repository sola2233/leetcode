/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
/** 
 * bst
 */
#include <vector>
using namespace std;
class Solution {
public:
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
};
// @lc code=end

