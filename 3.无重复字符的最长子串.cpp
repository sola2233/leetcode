/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
/** 
 * 子串问题用滑动窗口
 */
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int len = 0;
        // 左闭右开
        while (right < s.size())
        {
            char c = s[right];
            // 窗口扩大
            right++;
            // 更新窗口
            window[c]++;
            
            // 窗口缩小条件，缩小到窗口中没有重复字符
            while (window[c] > 1)
            {
                char d = s[left];
                // 缩小窗口
                left++;
                // 更新窗口
                window[d]--;
            }

            // 更新结果，因为此时窗口中无重复字符
            if (right - left > len)
                len = right - left;
        }

        return len;
    }
};
// @lc code=end

