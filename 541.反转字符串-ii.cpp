/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k)
        {
            // 左闭右开，反转 [i, i + k) 内的字符
            if (i + k <= n)
                // 剩余字符小于 2k 但大于 k 个
                reverse(s.begin() + i, s.begin() + i + k);
            else if (i + k > n)
                // 剩余字符小于 k 个，剩下的全部反转
                reverse(s.begin() + i, s.end());
        }

        return s;
    }
};
// @lc code=end

