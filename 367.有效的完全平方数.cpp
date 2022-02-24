/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
/** 
 * 二分搜索
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        // 左闭右闭
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            long pow = mid * mid;
            if (pow < num)
                left = mid + 1;
            else if (pow > num)
                right = mid - 1;
            else if (pow == num)
                return true;
        }
        return false;
    }
};
// @lc code=end

