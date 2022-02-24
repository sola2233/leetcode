/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
/** 
 * 栈的应用
 */
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> stk;
        for (auto& ch : s)
        {
            // 左括号入栈
            if (ch == '(' || ch == '{' || ch == '[')
                stk.push(ch);
            // 右括号检查是否和栈顶括号匹配
            else
            {
                // 栈为空或不匹配返回 false
                if (stk.empty() || stk.top() != pairs[ch])
                    return false;
                // 匹配直接弹出栈顶括号
                else
                    stk.pop();
            }
        }

        return stk.empty();
    }
};
// @lc code=end

