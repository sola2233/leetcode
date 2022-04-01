/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
/** 
 * 相比 227 题，需要考虑括号
 * 栈 + 递归
 */
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    // 遍历到的下标位置
    int pos;
    // 字符串长度
    int n;
    int calculate(string s) {
        pos = 0;
        n = s.size();
        int res = compute(s);

        return res;
    }

    // 递归计算括号内的表达式数值
    int compute(string& s) {
        stack<int> stk;
        int num = 0;
        char pre_sign = '+';
        // 下标改为全局变量，所以用 while 循环
        while (pos < n)
        {
            // 计算数字
            if (isdigit(s[pos]))
                num = 10 * num + (int)(s[pos] - '0');
            // 如果是符号
            if ((!isdigit(s[pos]) && !isspace(s[pos])) || pos == n - 1)
            {
                // 左括号，递归
                if (s[pos] == '(')
                {
                    pos++;
                    // 遇到右括号返回之后也没有问题，因为右括号右边一定是符号
                    num = compute(s);
                }
                // 正常处理符号
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
                // 右括号，返回
                if (s[pos] == ')')
                {
                    pos++;
                    break;
                }
                // 更新
                num = 0;
                pre_sign = s[pos];
            }
            // 更新 pos，要在 while 循环里更新
            pos++;
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

