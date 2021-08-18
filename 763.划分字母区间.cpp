/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
/**
 * 贪心思想
 * 可以先统计所有字母第一次和最后一次出现的位置，这样得到一个区间，原问题转化为一个区间问题
 * 统计重叠的区间、重叠区间的左边界和右边界
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        /** 字符串的长度 */
        int size = s.size();
        /** 保存每个字符的区间尾 */
        vector<int> chEnd(26, 0);
        /** 遍历字符串，得到每个字符区间尾 */
        for(int i = 0; i < size; i++)
        {
            int ch = s[i] - 'a';
            chEnd[ch] = i;
        }
        /** 区间头、区间尾 */
        int start = 0, end = 0;
        /** 返回值 */
        vector<int> ret;
        for(int i = 0; i < size; i++)
        {
            int ch = s[i] - 'a';
            end = max(end, chEnd[ch]);
            if(i == end)
            {
                ret.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ret;
    }
};
// @lc code=end

