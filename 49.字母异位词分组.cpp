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
    // 参考 leetcode 的映射关系
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> result;
    //     // 还能这么映射，惊了！！
    //     map<vector<int>, vector<string>> my_map;
    //     // 遍历字符串数组
    //     for (int i = 0; i < strs.size(); i++)
    //     {
    //         vector<int> flag(26,0);
    //         string s = strs[i];
    //         // 计数当前字符串
    //         for (char c : s)
    //            flag[c-'a']++;
    //         // 一类字母亦或词添加到 my_map[flag] 中
    //         my_map[flag].push_back(strs[i]);
    //     }

    //     for (auto item = my_map.begin(); item != my_map.end(); item++)
    //         result.push_back(item->second);
    //     return result;
    // }

    // 利用哈希表计数给每个字符串编码成另一个字符串，字母异位词编码相同
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hashmap;
        for (auto& str : strs)
            // 一类字母异位词添加到同一个分组
            hashmap[encode(str)].push_back(str);

        for (auto ite = hashmap.begin(); ite != hashmap.end(); ite++)
            res.push_back(ite->second);

        return res;
    }

    // 编码字符串
    string encode(string str)
    {
        string res(26, 0);
        for (auto& ch : str)
            res[ch - 'a']++;
        return res;
    }
};
// @lc code=end

