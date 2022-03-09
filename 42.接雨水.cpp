/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
/** 
 * 单调栈
 * 从前向后遍历，维持一个单调递减栈，即栈底到栈顶单调递减
 * 如果当前高度大于栈顶元素，就可以出栈并计算一次雨水了
 * 其实就是栈顶和栈顶的下一个元素以及要入栈的三个元素来接水
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int sum = 0; // 雨水总量
        // 首元素入栈，存放下标
        stk.push(0);
        for (int i = 1; i < height.size(); ++i)
        {
            // height[i] 大于栈顶元素的情况可以计算雨水，按行计算
            while (!stk.empty() && height[i] > height[stk.top()])
            {
                // 凹槽底部，实际上是要入栈元素 i，凹槽 bottom，栈顶元素 top 三个来计算雨水，按行计算
                int bottom = stk.top();
                stk.pop(); // 要出栈
                if (!stk.empty()) // 要判断是否非空
                {
                    int h = min(height[stk.top()], height[i]) - height[bottom];
                    int w = i - stk.top() - 1;
                    sum += h * w;
                }
            }
            // height[i] 小于等于栈顶元素的情况都直接入栈
            stk.push(i);
        }
        return sum;
    }
};
// @lc code=end

