/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hashmap;

        for (auto& ch : magazine)
            hashmap[ch]++;

        for (auto& ch : ransomNote)
        {
            hashmap[ch]--;
            if (hashmap[ch] < 0)
                return false;
        }

        return true;
    }
};
// @lc code=end

