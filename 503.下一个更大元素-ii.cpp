/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
/** 
 * 单调栈 + 循环数组
 * 单调栈中维护当前位置右边的更大的元素列表，从栈底到栈顶的元素是单调递减的。
 * 循环数组通常做法把数组长度翻一倍，实际可以通过下标取模来实现，不用真的把数组长度变成两倍
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    // 单调栈，从后向前遍历，维持一个单调递减栈
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     // 两倍数组长度，循环数组技巧
    //     int n = nums.size();
    //     vector<int> res(n);
    //     stack<int> stk;
    //     // 倒序遍历数组，构建单调栈，因为是循环数组，所以下标要取模
    //     for (int i = 2 * n - 1; i >= 0; --i)
    //     {
    //         // 删除栈顶小于 nums[i] 的元素
    //         while (!stk.empty() && stk.top() <= nums[i % n])
    //             stk.pop();
    //         // 找到下一个更大元素
    //         res[i % n] = stk.empty() ? -1 : stk.top();
    //         // 当前元素入栈
    //         stk.push(nums[i % n]);
    //     }

    //     return res;
    // }

    // 单调栈，从前向后遍历，维持一个单调递减栈
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 两倍数组长度，循环数组技巧
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        stk.push(0);
        // 正序遍历数组，构建单调栈，因为是循环数组，所以下标要取模
        for (int i = 1; i < 2*n; ++i)
        {
            // nums[i] 大于栈顶元素时可以出栈并设置下一个更大元素
            while (!stk.empty() && nums[i % n] > nums[stk.top()])
            {
                int mid = stk.top();
                stk.pop();
                // 设置栈顶元素的下一个更大元素
                res[mid] = nums[i % n];
            }
            // nums[i] 小于等于栈顶元素直接入栈
            stk.push(i % n);
        }

        return res;
    }
};
// @lc code=end

