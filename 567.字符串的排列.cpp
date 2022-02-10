/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
/** 
 * 双指针，子串问题用滑动窗口解决
 * 其实只要两个距离为 s1.size() 的指针同步移动，判断子串字符是否和 s1 相等即可，即固定长度的滑动窗口
 * 用滑动窗口，加快了判断的过程，因为建立了哈希表
 */
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c : s1) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        // 左闭右开
        while (right < s2.size())
        {
            char c = s2[right]; // c 是将移入滑动窗口的字符
            // 滑动窗口扩大
            right++;
            // 更新数据：window 和 valid
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // 滑动窗口缩小条件：子串和 s1 长度相等
            if (right - left == s1.size())
            {
                // 更新结果：满足条件返回
                if (valid == need.size())
                    return true;
                
                char d = s2[left]; // d 是将移出窗口的字符
                // 窗口缩小
                left++;
                // 更新数据
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }

        // 循环中没找到就是没有
        return false;
    }
};
// @lc code=end

