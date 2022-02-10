/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
/** 
 * 子串问题用滑动窗口
 * 和567题字符串的排列类似
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (char c : p) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        vector<int> res; // 返回结果
        // 左闭右开
        while (right < s.size())
        {
            char c = s[right];
            // 窗口扩大
            right++;
            // 更新
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            // 窗口缩小条件
            if (right - left == p.size())
            {
                // 更新结果
                if (valid == need.size())
                    res.push_back(left);

                char d = s[left];
                // 窗口缩小
                left++;
                // 更新
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }

        return res;
    }
};
// @lc code=end

