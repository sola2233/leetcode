/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
/** 
 * 数组 + 单调栈
 */
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stk; // 用 string 模拟栈
        vector<int> count(26); // 计算每个字符出现次数
        vector<bool> is_in_stack(26); // 判断字符是否在栈中

        // 遍历计数
        for (auto ch : s)
            ++count[ch - 'a'];
        
        // 遍历，单调栈
        for (auto ch : s)
        {
            // 遍历过一个字符，计数减一
            --count[ch - 'a'];
            // 当前字符 ch 已经在栈中则跳过
            if (is_in_stack[ch - 'a'])
                continue;
            // 删掉栈顶比当前元素大的元素
            while (!stk.empty() && stk.back() > ch)
            {
                // 如果后面还有栈顶字符，就删掉它
                if (count[stk.back() - 'a'] > 0)
                {
                    is_in_stack[stk.back() - 'a'] = false;
                    stk.pop_back();
                }
                else
                    break;
            }
            // 当前字符入栈
            stk.push_back(ch);
            is_in_stack[ch - 'a'] = true;
        }
        return stk;
    }
};
// @lc code=end

