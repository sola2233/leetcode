/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
/** 
 * 单调栈
 * 这里应该是个递增栈，从栈底向栈顶递增
 * 但是其实不一定
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string smallestSubsequence(string s) {
        string stk;
        vector<int> count(26);
        vector<bool> is_in_stk(26);

        // 遍历计数
        for (auto& ch : s)
            ++count[ch - 'a'];
        
        // 单调栈
        for (auto& ch : s)
        {
            // 遍历到就计数减一
            --count[ch - 'a'];
            // 如果已经在栈中，跳过
            if (is_in_stk[ch - 'a'])
                continue;
            // 删除栈顶比当前字符字典序大的字符，如果能删的话
            while (!stk.empty() && stk.back() > ch)
            {
                // 如果栈顶字符后面还有，就可以删
                if (count[stk.back() - 'a'] > 0)
                {
                    is_in_stk[stk.back() - 'a'] = false;
                    stk.pop_back();
                }
                else
                    // 否则只能结束删除
                    break;
            }
            // 当前字符入栈
            stk.push_back(ch);
            is_in_stk[ch - 'a'] = true;
        }
        return stk;
    }
};
// @lc code=end

