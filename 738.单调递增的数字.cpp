/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
/** 
 * 贪心
 * 局部最优：遇到strNum[i - 1] > strNum[i]的情况，让strNum[i - 1]--，
 * 然后strNum[i]给为9，可以保证这两位变成最大单调递增整数。
 * 全局最优：得到小于等于N的最大单调递增的整数。
 * 但这里局部最优推出全局最优，还需要其他条件，即遍历顺序，和标记从哪一位开始统一改成9。
 * 
 * 实际上，只要出现不满足递增数字的情况，一定是从某个数开始，后面的都是 9，
 * 并且这个数的值减 1，只需要找出这个数的位置即可，即代码中的 idx - 1 位置
 * 时间复杂度 o(logn)，数字大小 n，一共 logn 位，遍历即可
 * 
 */
#include <string>
using namespace std;
class Solution {
public:
#if 1   // 贪心
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int sz = str.size();
        // 从后往前遍历
        int idx = sz; // 记录从哪开始赋值 9，初始化为 sz，防止错误赋值
        for (int i = sz - 1; i > 0; --i)
        {
            if (str[i] < str[i - 1])
            {
                idx = i;
                str[i - 1]--;
            }
        }
        // 赋值 9
        for (int i = idx; i < sz; ++i)
            str[i] = '9';

        // 如果 n 是一位数，那就是他自己，也没问题
        return stoi(str);
    }
#endif

#if 0   // 暴力，会超时
    int monotoneIncreasingDigits(int n) {
        for (int i = n; i >= 0; --i)
        {
            if (isValid(i))
                return i;
        }

        return 0;
    }

    // 判断是否是递增数
    bool isValid(int n)
    {
        int max_i = 10;
        while (n)
        {
            int i = n % 10;
            if (i <= max_i)
            {
                max_i = i;
                n /= 10;
            }
            else
                return false;
        }

        return true;
    }
#endif
};
// @lc code=end

