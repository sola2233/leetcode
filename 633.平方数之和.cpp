/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
/** 
 * 双指针
 * 解题策略：
 * 两个指针反向遍历(0-c)
 */
#include <math.h>
class Solution {
public:
    bool judgeSquareSum(int c) {
        /* note c的范围是uint_32的所有值，必须要long */
        long l = 0, r = sqrt(c);
        long sum = 0;
        while(l <= r)
        {
            sum = l * l + r * r;
            if(sum == c)
                return true;
            else if(sum < c)
                ++l;
            else
                --r;
        }
        return false;
    }
};
// @lc code=end

