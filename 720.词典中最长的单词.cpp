/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
/** 
 * 方法1.排序 + hashset
 * 方法2.前缀树
 */
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string longestWord(vector<string>& words) {
        // 排序，按长度升序，长度相同按字典序降序
        sort(words.begin(), words.end(), [](auto a, auto b) {
            return a.size() < b.size() || (a.size() == b.size() && a > b);
        });

        // 哈希
        unordered_set<string> hashset = {""}; // 要放一个空串进去
        string res;
        for (auto& word : words)
        {
            if (hashset.count(word.substr(0, word.size() - 1)))
            {
                hashset.insert(word); // 满足条件再加入 hashset
                res = word;
            }
        }
        return res;
    }
};
// @lc code=end

