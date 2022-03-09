/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
/** 
 * 单调栈
 * 从前往后遍历，维持一个单调递增栈，即栈底到栈顶单调增，和 42 题接雨水相反
 * [好的解释](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/bao-li-jie-fa-zhan-by-liweiwei1419/)
 * 所以本题单调栈的顺序正好与接雨水反过来
 * 此时大家应该可以发现其实就是栈顶和栈顶的下一个元素以及要入栈的三个元素组成了我们要求最大面积的高度和宽度
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        // 前后加两个哨兵
        heights.insert(heights.begin(), 0);
        heights.push_back(0); // 不加的话栈中剩下的矩形就没有计算了
        // 首元素入栈，记录下标
        stk.push(0);
        // 遍历
        int area = 0;
        for (int i = 1; i < heights.size(); ++i)
        {
            // 当前高度小于栈顶元素时，计算面积
            while (!stk.empty() && heights[i] < heights[stk.top()])
            {
                // 计算以当前栈顶元素为高的矩形面积
                int mid = stk.top();
                stk.pop();
                int h = heights[mid];
                int w = i - stk.top() - 1;
                area = max(area, h * w);
            }
            // 其余情况直接入栈
            stk.push(i);
        }
        return area;
    }
};
// @lc code=end

