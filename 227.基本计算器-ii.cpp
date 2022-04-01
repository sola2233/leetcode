/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
/** 
 * 最简单的四则运算，因为里面没有括号
 * 直接用一个栈存放整数即可
 */
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        // 存放整数
        stack<int> stk;
        // 上一个符号
        char pre_sign = '+';
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            // 计算数字大小
            if (isdigit(s[i]))
                num = 10 * num + (s[i] - '0');
            // 当前字符是符号且不是空格，或者已经是最后一个字符，则和栈顶元素计算一个结果
            // 这里必须是 if 不能用 if else，因为最后一个字符如果是数字，就不会运行这一步
            if ((!isdigit(s[i]) && !isspace(s[i])) || i == n - 1)
            {
                // 要写在 switch 外面，不然会重复定义
                int pre_num = 0;
                switch (pre_sign)
                {
                    case '+':
                        stk.push(num);
                        break;
                    case '-':
                        stk.push(-num);
                        break;
                    case '*':
                        pre_num = stk.top();
                        stk.pop();
                        stk.push(pre_num * num);
                        break;
                    case '/':
                        pre_num = stk.top();
                        stk.pop();
                        stk.push(pre_num / num);
                        break;
                }
                // 做一些更新工作
                num = 0;
                pre_sign = s[i];
            }
        }

        int sum = 0;
        while (!stk.empty())
        {
            sum += stk.top();
            stk.pop();            
        }
        return sum;
    }
};
// @lc code=end

