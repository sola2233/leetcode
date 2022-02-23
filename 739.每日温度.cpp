/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
/** 
 * 单调栈
 * 构建一个单调递减栈，从栈底到栈顶递减
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    // 从后向前遍历，维持一个单调递减栈
    // vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     int n = temperatures.size();
    //     vector<int> res(n);
    //     stack<int> stk;
    //     // 倒序遍历，构建单调递减栈，储存下标
    //     for (int i = n - 1; i >= 0; --i)
    //     {
    //         // 删除栈顶小于等于 temperatures[i] 的元素
    //         while (!stk.empty() && temperatures[stk.top()] <= temperatures[i])
    //             stk.pop();
    //         // 找到下一个更高温度
    //         res[i] = stk.empty() ? 0 : stk.top() - i;
    //         // 当前元素入栈
    //         stk.push(i);
    //     }

    //     return res;
    // }

    // 从前向后遍历，维持一个单调递减栈
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> stk;
        stk.push(0);
        // 正序遍历，构建单调递减栈，储存下标
        for (int i = 1; i < n; ++i)
        {
            // temperatures[i] 大于栈顶元素可以出栈，并设置下一个更高温度
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()])
            {
                // 栈顶元素出栈
                int mid = stk.top();
                stk.pop();
                // 设置到下一个最高温度的天数
                res[mid] = i - mid;
            }
            // temperatures[i] 小于等于栈顶元素直接入栈
            stk.push(i);
        }

        return res;
    }
};
// @lc code=end

