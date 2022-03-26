/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
/** 
 * 具体看官方题解
 * 数学：[1, n] 中，对于质因子 p
 * 1.p 的倍数有 n1 = n / p 个
 * 2.p^2 的倍数有 n2 = n^2 / p 个
 * 3.p^3 的倍数有 n3 = n^3 / p 个
 * ......
 * k.p^k 的倍数有 nk = n^k / p 个 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        // 第 k 次循环就计算 p^k 的倍数个数
        while (n)
        {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
// @lc code=end

