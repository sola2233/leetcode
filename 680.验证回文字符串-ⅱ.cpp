/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
/** 
 * 双指针
 * 解题策略：
 * 两个指针反向遍历，有两种情况可以删除
 * 1.要删除的字符为左指针位置
 * 2.要删除的字符为右指针位置
 */
#include <string>
using namespace std;
class Solution {
public:
    /**
     * 判断是否是回文 
     * @param l 左指针
     * @param r 右指针
     */
    bool isPalindrome(const string &s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }

    bool validPalindrome(string s) {
        /** 双向遍历 */
        for(int l = 0, r = s.size() - 1; l < r; ++l, --r)
        {
            if(s[l] != s[r])
            {
                return isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1);
            }
        }
        return true;
    }
};
// @lc code=end

