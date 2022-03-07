/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
/** 
 * 方法1.回溯法，带记忆，并且是从字符串分割角度来考虑的，具体看 carl
 * 方法2.动态规划，完全背包，看 carl
 * dp[i]: 字符串 s 前 i 个字符组成的字符串 s[0..i-1] 是否能被空格拆分成若干个字典中出现的单词
 * 状态转移: 如果 substr(j, i - j) 在字典中，且 dp[j] 为 true，则 dp[i] 也为 true
 * base case: dp[0] = true
 * 遍历顺序无所谓，但是先遍历背包比较好，本题
 */
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1);
        unordered_set<string> hashset;
        // 建立 hashset
        for (auto& word : wordDict)
            hashset.insert(word);
        // base case
        dp[0] = true;
        // 遍历背包
        for (int i = 1; i <= n; ++i)
        {
            // 遍历物品
            for (int j = 0; j < i; ++j)
            {
                string word = s.substr(j, i - j);
                if (hashset.count(word) && dp[j])
                    dp[i] = true;
            }
        }
        return dp[n];
    }
};
// @lc code=end

