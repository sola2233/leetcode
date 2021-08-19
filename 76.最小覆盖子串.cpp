/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
/** 
 * 双指针，此处用滑动窗口
 * 解题策略：
 * 
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<bool> isNeed(128, false);
        /** 统计t中的字符 */
        for (int i = 0; i < t.size(); ++i) 
        {
            isNeed[t[i]] = true;
            ++need[t[i]];
        }
        /** 滑动窗口左指针 */
        int l = 0, needCnt = t.size();
        /** 最小区间的左指针和区间大小 */
        int min_l = 0, min_size = s.size()+1;
        /** 从左往右遍历字符串s */
        for(int r = 0; r < s.size(); ++r)
        {
            if(isNeed[s[r]])
            {
                /** 右移得到一个所需字符，减少相应的数量 */
                --need[s[r]];       /* note 先减再判断，并且所需字符是可以小于0的 */
                if(need[s[r]] >= 0)
                    --needCnt;
                /** 
                 * 若滑动窗口已经包含所有需要的字符 
                 * 则尝试将l右移，排除不需要的字符
                 */
                while(needCnt == 0)
                {
                    /** 保存最小区间 */
                    if(r-l+1 < min_size)
                    {
                        min_l = l;
                        min_size = r - l + 1;
                    }
                    /* note 所需字符是可能小于0的，++need[s[l]]这步很重要，必须要加完大于0
                     * 删除一个所需字符 
                     */
                    if(isNeed[s[l]] && ++need[s[l]] > 0)
                        ++needCnt;
                    ++l;
                }
            }
        }
        return min_size > s.size()? "": s.substr(min_l, min_size);
    }
};
// @lc code=end

