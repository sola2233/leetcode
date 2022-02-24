/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
/** 
 * 奇怪的 hash 映射
 * [参考](https://leetcode-cn.com/problems/group-anagrams/solution/zi-mu-yi-wei-fen-zu-c-ji-shu-fang-shi-by-vvbn/)
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        // 还能这么映射，惊了！！
        map<vector<int>, vector<string>> my_map;
        // 遍历字符串数组
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> flag(26,0);
            string s = strs[i];
            // 计数当前字符串
            for (char c : s)
               flag[c-'a']++;
            // 一类字母亦或词添加到 my_map[flag] 中
            my_map[flag].push_back(strs[i]);
        }

        for (auto item = my_map.begin(); item != my_map.end(); item++)
            result.push_back(item->second);
        return result;
    }
};
// @lc code=end

