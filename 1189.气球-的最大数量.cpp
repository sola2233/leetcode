/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // 记录 text 中字符
        unordered_map<char, int> memo;
        for (char c : text)
            memo[c]++;

        memo['o'] /= 2;
        memo['l'] /= 2;

        return min({memo['b'], memo['a'], memo['l'], memo['o'], memo['n']}); 
    }
};
// @lc code=end

