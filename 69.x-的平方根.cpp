/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
/** 
 * 二分查找
 */
class Solution {
public:
    int mySqrt(int x) {
        /** 0的情况单独考虑 */
        if(x == 0)
            return x;
        /** 左指针l从1开始，从0开始会出现除0的情况 */
        int l = 1, r = x, mid, sqrt;
        /** 二分查找，使用左闭右闭写法 */
        while(l <= r)
        {
            mid = l + (r-l) / 2;
            sqrt = x / mid;
            if(mid == sqrt)
                return mid;
            else if(mid > sqrt)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return r;
    }
};
// @lc code=end

