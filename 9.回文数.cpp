/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
/** 
 * 方法1.转字符串 + 双指针
 * 方法2.不转字符串，将数翻转过来
 * 直接翻转可能会溢出，所以翻转一半，当 x 小于等于翻转后的数 y 时，翻转了一半，会遇到两种情况
 * 1.长度为偶数时，x == y
 * 2.长度为奇数时，x < y，此时要将 x 与 y / 10 比较，因为中间一位不用比较
 */
class Solution {
public:
    bool isPalindrome(int x) {
        // 负数和以0结尾都不是回文
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        
        // 考虑到将整个数全部翻转可能会溢出，所以反转一半
        int y = 0;
        while (x > y)
        {
            y = (y * 10 + x % 10);
            x /= 10;
        }

        return x == y || x == (y / 10);
    }
};
// @lc code=end

