/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        // 负例
        if (numRows == 1)
            return s;

        vector<string> ans(numRows);
        string res;
        int row = 0, n = s.size();
        bool go_down = false; // 控制 row 向上或向下
        // 遍历 s
        for (int i = 0; i < n; ++i)
        {
            ans[row] += s[i];
            // row 递增或递减，为 0 时递增，到 numRows - 1 时递减
            if (row == 0 || row == numRows - 1)
                go_down = !go_down;
            row = (go_down ? row + 1 : row - 1);
        }
        // 拼接
        for (auto& str : ans)
            res += str;

        return res;
    }
};
// @lc code=end

