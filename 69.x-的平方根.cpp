/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
/** 
 * 二分查找
 * 为什么最后返回 right？
 * 最后一步时区间中一定只有一个数 k = left = right = mid，我们要得到的整数 k * k <= x，如果
 * 1. k * k < x，则 left += 1，此时 left * left > x，所以返回 right
 * 2. k * k > x，则 right -= 1，此时 left * left > x，所以返回 right
 * 3. k * k == x，则返回 mid = k 即可
 */
class Solution {
public:
    int mySqrt(int x) {
        // 负例
        if(x == 0) return x;
        // 左指针l从1开始，从0开始会出现除0的情况
        int left = 1, right = x;
        // 左闭右闭，每次比较区间中点 mid * mid 和 x的大小关系
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            // 可能会溢出，此处用除法代替乘法，比较 mid 和 x / mid
            if (mid < x / mid)
                left = mid + 1;
            else if (mid > x / mid)
                right = mid - 1;
            // 只有 x 的平方根是整数时，才能在循环中返回正确答案
            else if (mid == x / mid)
                return mid;
        }

        // 返回 right 或 left - 1
        return right;
    }
};
// @lc code=end

