/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
/** 
 * 双指针
 * 解题策略：先排序再检查子序列
 * 排序按照字符串长度降序排序，长度相同按字典序升序排序
 * 用双指针检查是否是子序列
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    /** 判断s是否是ss的子序列 */
    bool isSubsequence(string ss, string s)
    {
        int j = 0;
        /** 遍历ss，计数s有多少字符在ss中 */
        for(int i = 0; i < ss.size(); i++)
        {
            if(ss[i] == s[j])
                ++j;
        }
        return j == s.size() ? true : false;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        /** 按长度降序排序，长度相同按字典序升序排序 */
        sort(dictionary.begin(), dictionary.end(), [](string& a, string& b) {
            return a.size() > b.size() || (a.size() == b.size() && a < b);
        });
        /** 遍历字典 */
        for(const string& str : dictionary)
        {
            if(isSubsequence(s, str))
                return str;
        }
        return "";
    }
};
// @lc code=end

