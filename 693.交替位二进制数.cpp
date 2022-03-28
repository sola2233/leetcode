/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
/** 
 * 方法1.暴力移位判断相邻两位
 * 方法2.当 n 的二进制数 01 交替时，(n >> 1) ^ n = a 为全 1 的数 0xffffffff
 *        此时 a & (a + 1) == 0
 */
class Solution {
public:
    bool hasAlternatingBits(int n) {
        // 必须是 long 否则会溢出
        long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};
// @lc code=end

