/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
/** 
 * kmp
 * 可以利用 next 表的性质
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int m = s.size();
        // 构建 next 表
        vector<int> next(m);
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < m; ++i)
        {
            while (j > 0 && s[j] != s[i])
                j = next[j - 1];
            if (s[j] == s[i])
                j++;
            next[i] = j;
        }

        // next[m-1] != 0 说明字符串 s 有最长相同真前后缀
        // next[m-1] 就是字符串 s 的最长相等真前后缀
        // m - next[m-1] 就是重复子串的长度
        // 如果能被字符串 s 的长度 m 整除，就返回 true
        if (next[m - 1] != 0 && m % (m - next[m - 1]) == 0)
            return true;
        return false;
    }
};
// @lc code=end

