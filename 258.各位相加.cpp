/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        
        int sum = 0;
        while (true)
        {
            while (num)
            {
                sum += num % 10;
                num = num / 10;
            }

            if (sum < 10)
                break;
            else
            {
                num = sum;
                sum = 0;
            }
        }

        return sum;
    }
};
// @lc code=end

