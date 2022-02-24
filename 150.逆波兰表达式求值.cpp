/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
/** 
 * 栈应用
 */
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums; // 数字栈
        unordered_set<string> hashset{"+", "-", "*", "/"};
        // 遍历
        for (auto& s : tokens)
        {
            // 遇到符号出栈两个数
            if (hashset.count(s))
            {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                int ans;

                if (s == "+")
                    ans = left + right;
                else if (s == "-")
                    ans = left - right;
                else if (s == "*")
                    ans = left * right;
                else
                    ans = left / right;
                nums.push(ans);
            }
            // 数字入栈
            else
                nums.push(stoi(s));
        }

        return nums.top();
    }
};
// @lc code=end

