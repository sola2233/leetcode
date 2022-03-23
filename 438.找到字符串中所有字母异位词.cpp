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
        vector<int> need(26);
        vector<int> wind(26);
        for (auto& ch : p)
            need[ch - 'a']++;
        
        vector<int> res;
        // 滑动窗口，左闭右开 [left, right)
        int left = 0, right = 0;
        while (right < s.size())
        {
            wind[s[right] - 'a']++;
            right++;
            // 维持一个定长滑动窗口
            if (right - left >= p.size())
            {
                if (wind == need)
                    res.push_back(left);
                wind[s[left] - 'a']--;
                left++;
            }
        }
        return res;
    }    

    // 感觉写的好复杂，有空再看看
    // vector<int> findAnagrams(string s, string p) {
    //     unordered_map<char, int> need, window;
    //     // p 中字符计数
    //     for (char c : p) need[c]++;

    //     int left = 0, right = 0;
    //     int valid = 0;
    //     vector<int> res; // 返回结果
    //     // 左闭右开，维持一个定长为 p.size 的滑动窗口
    //     while (right < s.size())
    //     {
    //         char c = s[right];
    //         // 窗口扩大
    //         right++;
    //         // 更新
    //         if (need.count(c))
    //         {
    //             window[c]++;
    //             if (window[c] == need[c])
    //                 valid++;
    //         }
    //         // 窗口缩小条件，维持一个定长为 p.size 的滑动窗口
    //         if (right - left == p.size())
    //         {
    //             // 如果是 p 的异位词就更新结果，否则直接缩小窗口
    //             if (valid == need.size())
    //                 res.push_back(left);

    //             char d = s[left];
    //             // 窗口缩小
    //             left++;
    //             // 更新窗口
    //             if (need.count(d))
    //             {
    //                 if (window[d] == need[d])
    //                     valid--;
    //                 window[d]--;
    //             }
    //         }
    //     }

    //     return res;
    // }
};
// @lc code=end

