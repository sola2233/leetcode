/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
/** 
 * 单调栈，维护一个单调递减栈
 */
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        stack<int> stk; // 存放下标
        stk.push(0); // 首元素入栈
        int max_incr = 0; // 保存最大增量
        for (int i = 1; i < nums.size(); ++i)
        {
            // 如果当前元素比栈顶元素大，计算增量
            if (!stk.empty() && nums[i] > nums[stk.top()])
                max_incr = max(max_incr, nums[i] - nums[stk.top()]);
            // 否则入栈
            else
                stk.push(i);
        }

        return max_incr == 0 ? -1 : max_incr;
    }
};
// @lc code=end

