/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
/** 
 * 方法1.移位实现位计数
 * 方法2.Brian Kernighan 算法
 * 记 f(x) 表示 x 和 x−1 进行与运算所得的结果
 * 即 f(x) = x & (x-1)
 * 那么 f(x) 恰为 x 删去其二进制表示中最右侧的 1 的结果
 */
class Solution {
public:
    // 方法1
    // int hammingDistance(int x, int y) {
    //     // 异或
    //     int a = x ^ y;
    //     // 计算 a 的二进制 1 个数
    //     int count = 0;
    //     while (a)
    //     {
    //         count += a & 0b1;
    //         a >>= 1;
    //     }
    //     return count;
    // }

    // 方法2
    int hammingDistance(int x, int y) {
        // 异或
        int a = x ^ y;
        // 计算 a 的二进制 1 个数
        int count = 0;
        while (a)
        {
            count++;
            a &= a - 1;
        }
        return count;
    }
};
// @lc code=end

