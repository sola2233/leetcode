/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
/** 
 * 桶排序
 * 参考https://leetcode-cn.com/problems/sort-characters-by-frequency/solution/gen-ju-zi-fu-chu-xian-pin-lu-pai-xu-by-l-zmvy/
 * 算法步骤：
 * 1.遍历字符串，统计每个字符出现的频率，同时记录最高频率 max_freq
 * 2.创建桶，存储从 1 到 max_freq 的每个出现频率的字符；
 * 3.按照出现频率从大到小的顺序遍历桶，对于每个出现频率，获得对应的字符，
 * 然后将每个字符按照出现频率拼接到排序后的字符串。
 */
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 给定一个字符串，请将字符串里的字符按照出现的频率降序排列
     * @param s 给定的字符串
     * @return 按要求排序好的字符串
     */
    string frequencySort(string s) {
        // 创建哈希表，记录最高频率
        unordered_map<char, int> mp;
        int max_freq = 0;
        int size = s.size();
        for (const auto &ch : s)
            max_freq = max(max_freq, ++mp[ch]);
        
        // 创建桶，长度为 max_freq+1，因为加上了频率为0的
        vector<string> buckets(max_freq + 1);
        for (const auto &p : mp)
            // 拼接相同频率的字符
            buckets[p.second].push_back(p.first);

        // 创建返回字符串，依次拼接出现频率最高的字符
        string ret;
        for (int i = max_freq; i > 0; --i)
        {
            string &bucket = buckets[i];
            for (const auto &ch : bucket)
            {
                for (int k = 0; k < i; ++k)
                    ret.push_back(ch);
            }
        }

        return ret;
    }
};
// @lc code=end

