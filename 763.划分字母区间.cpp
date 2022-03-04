/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
/**
 * 贪心思想
 * 可以分为如下两步：
 * 1.统计每一个字符最后出现的位置
 * 2.从头遍历字符，并更新字符的最远出现下标，
 * 如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ch_end(26, 0); // 保存每个字符最后出现的位置
        // 遍历字符串
        for(int i = 0; i < n; i++)
        {
            int ch = s[i] - 'a';
            ch_end[ch] = i;
        }
        vector<int> res;
        int start = 0, end = 0;
        // 遍历字符串
        for(int i = 0; i < n; i++)
        {
            int ch = s[i] - 'a';
            end = max(end, ch_end[ch]);
            // 到达某个字符的最远边界，划分一次
            if(i == end)
            {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
// @lc code=end

