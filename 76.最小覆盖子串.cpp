/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
/** 
 * 双指针，此处用滑动窗口
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0; // 滑动窗口
        int valid = 0; // 满足条件的字符个数
        int start = 0, len = INT32_MAX; // 记录最小覆盖子串的起始索引及长度
        // 左闭右开
        while (right < s.size())
        {
            char c = s[right]; // c 是将移入窗口的字符
            // 滑动窗口扩大
            right++;
            // 扩大时更新数据：window 和 valid
            if (need.count(c))
            {
                // 先更新 window 在判断 valid 是否要更新
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // 滑动窗口缩小条件
            while (valid == need.size())
            {
                // 更新结果：子串位置
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }

                char d = s[left]; // d 是将移出窗口的字符
                // 滑动窗口缩小
                left++;
                // 缩小时更新数据：window 和 valid
                if (need.count(d))
                {
                    // 先判断 valid 是否要更新，再更新 window
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }

        // 考虑负例情况
        return len == INT32_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end

