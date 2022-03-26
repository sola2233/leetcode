/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        for (auto& str : ops)
        {
            if (str == "+")
            {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.push(first);
                stk.push(first + second);
            }
            else if (str == "D")
                stk.push(2 * stk.top());
            else if (str == "C")
                stk.pop();
            else
                stk.push(stoi(str));
        }

        int res = 0;
        while (!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

