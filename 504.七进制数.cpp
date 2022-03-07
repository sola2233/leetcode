/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
/** 
 * 模拟题
 * 题解是用了一个字符串模拟栈，x 不断模 7 再除以 7，最后反转栈就行了
 */
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    // string convertToBase7(int num) {
    //     int x = abs(num);
    //     string res;
    //     if (num == 0)
    //         return "0";
    //     if (num < 0)
    //         res.push_back('-');
        
    //     int base = 1; // base 是 7 的幂，第一个循环主要是为了找到最大的幂
    //     // 等号是为了处理正好等于 7 的幂次的数，直接用 base，不用计数
    //     while (base <= x)
    //         base *= 7;

    //     while (base > 1)
    //     {
    //         base /= 7;
    //         res += to_string(x / base);
    //         x = x % base;
    //     }

    //     return res;
    // }

    string convertToBase7(int num) {
        int x = abs(num);
        string res;
        if (num == 0)
            return "0";
        
        do
        {
            res += to_string(x % 7);
            x /= 7;
        } while (x > 0);

        if (num < 0)
            res += "-";

        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

