/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
/** 
 * 贪心
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0; // 开始有多少钱
        for (int i = 0; i < bills.size(); ++i)
        {
            // 情况1，顾客给 5 元
            if (bills[i] == 5)
                five++;
            // 情况2，给 10 元
            else if (bills[i] == 10)
            {
                if (five == 0)
                    return false;
                ten++;
                five--;
            }
            // 情况3，给 20 元
            else
            {
                // 记录 20 其实没有意义了
                twenty++;
                // 贪心，优先找 10 元和 5 元
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                // 没有 10 元再找 5 元
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};
// @lc code=end

