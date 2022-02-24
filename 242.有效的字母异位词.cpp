/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
/** 
 * hashmap
 */
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashmap;
        for (auto& ch : s)
            hashmap[ch]++;
        
        for (auto& ch : t)
        {
            hashmap[ch]--;
            if (hashmap[ch] == 0)
                hashmap.erase(ch);
        }

        return hashmap.size() == 0 ? true : false;
    }
};
// @lc code=end

