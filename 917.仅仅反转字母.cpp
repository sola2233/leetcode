/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
/** 
 * 双指针 + hash快速查找
 * hash 可以不用，用 <ctype> 里的 isapha() 函数判断是不是字母
 */
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        // 构建 hashset
        unordered_set<char> hashset;
        for (char ch = 'a'; ch <= 'z'; ++ch)
            hashset.insert(ch);
        for (char ch = 'A'; ch <= 'Z'; ++ch)
            hashset.insert(ch);
        // 双指针
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            while (!hashset.count(s[right]) && left < right)
                --right;
            while (!hashset.count(s[left]) && left < right)
                ++left;
            swap(s[left], s[right]);
            ++left;
            --right;
        }

        return s;
    }
};
// @lc code=end

