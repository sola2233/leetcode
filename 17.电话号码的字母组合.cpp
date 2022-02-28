/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
/** 
 * 回溯法
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    // 建立数字到字符的映射
    vector<string> letter_map = { "",   // 0
                                "",     // 1
                                "abc",  // 2
                                "def",  // 3
                                "ghi",  // 4
                                "jkl",  // 5
                                "mno",  // 6
                                "pqrs", // 7
                                "tuv",  // 8
                                "wxyz", // 9
                                };
    vector<string> res;
    string path;
    vector<string> letterCombinations(string digits) {
        // 负例
        if (digits.empty())
            return res;
        backtracking(digits, 0);
        return res;
    }

    /**
     * 回溯法 
     * @param digits 输入字符，如“23”
     * @param idx 当前遍历的 digits 字符串位置，这里就是下标，不用加1，[0, digits.size() - 1]
     *            这里的 idx 和之前的 start_idx 语义不一样了
     */
    void backtracking(const string& digits, int idx)
    {
        // 终止条件
        if (path.size() == digits.size())
        {
            res.push_back(path);
            return;
        }

        // 在选择列表做选择
        int digit = digits[idx] - '0'; // atoi(&digits[idx])
        for (auto& ch : letter_map[digit])
        {
            path.push_back(ch);
            backtracking(digits, idx + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

