/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
/** 
 * 回溯
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> res; // 存放结果
    string path;        // 存放路径
    vector<string> generateParenthesis(int n) {
        backtracking(n, n);

        return res;
    }

    /**
     * 回溯法，穷举所有有效结果
     * @param left 剩余左括号数
     * @param right 剩余右括号数
     */
    void backtracking(int left, int right)
    {
        // 剪枝
        if (right < left) // 左括号应该比右括号少，因为一定是先放左括号，再放右括号
            return;
        if (left < 0 || right < 0)
            return;
        // base case
        if (left == 0 && right == 0)
        {
            res.push_back(path);
            return;
        }

        path.push_back('(');
        backtracking(left - 1, right); // 递归
        path.pop_back(); // 回溯

        path.push_back(')');
        backtracking(left, right - 1); // 递归
        path.pop_back(); // 回溯
    }
};
// @lc code=end

