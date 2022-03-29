/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
/** 
 * 滑动窗口
 * 对于合法的子串 sum(所有字符出现的总次数) - max_cnt(出现次数最多的字符出现次数) = 其他字符出现次数 <= k
 * 上面的条件就是合法的窗口，当不满足时，窗口收缩
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> cnt(26, 0); // 记录每个字符出现次数
        int sum = 0;            // 所有字符出现的总次数
        int max_cnt = 0;        // 出现次数最多的字符出现次数
        int res = 0;            // 记录最大长度
        // 左闭右开
        int left = 0, right = 0;
        while (right < s.size())
        {
            int i = s[right] - 'A';
            // 更新窗口
            cnt[i]++;
            sum++;
            max_cnt = *max_element(cnt.begin(), cnt.end());
            // 扩大窗口
            right++;
            // 更新结果
            if (sum - max_cnt <= k)
                res = max(res, right - left);
            // 窗口收缩条件
            while (sum - max_cnt > k)
            {
                int i = s[left] - 'A';
                cnt[i]--;
                sum--;
                max_cnt = *max_element(cnt.begin(), cnt.end());
                // 扩大窗口
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

