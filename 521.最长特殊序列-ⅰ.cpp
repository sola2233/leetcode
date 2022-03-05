/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLUSlength(string a, string b) {
        int m = a.size(), n = b.size();
        return a == b ? -1 : max(m, n);
    }
};
// @lc code=end

