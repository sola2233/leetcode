/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
/** 
 * 栈
 */
#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        string res; // 字符串模拟栈
        for (auto& ch : s)
        {
            // 栈非空，栈顶元素与 ch 相等，删除栈顶元素
            if (!res.empty() && res.back() == ch)
                res.pop_back();
            // 其余情况直接入栈
            else
                res.push_back(ch);
        }

        return res;
    }
};
// @lc code=end

