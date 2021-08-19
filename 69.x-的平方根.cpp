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
        int l = 1, r = x, mid, sqrt;
        /** 二分查找 */
        while(l <= r)
        {
            mid = l + (r-l) / 2;
            sqrt = x / mid;
            if(sqrt == mid)
                return mid;
            else if(sqrt < mid)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return r;
    }
};
// @lc code=end

