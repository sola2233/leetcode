/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
/** 
 * 单调栈 + hash
 * 单调栈中维护当前位置右边的更大的元素列表，从栈底到栈顶的元素是单调递减的。
 * 结果存到 hashmap 中，而不是数组中了，因为这里有两个数组，存到 hashmap 中可以给 nums1 用
 */
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    // 单调栈，从后向前遍历，维持单调递减栈
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_map<int, int> hashmap;
    //     stack<int> stk;
    //     // 从后往前，用单调栈对 nums2 构建下一个更大元素
    //     for (int i = nums2.size() - 1; i >= 0; --i)
    //     {
    //         // 先删除单调栈中没有 nums2[i] 大的元素
    //         while (!stk.empty() && stk.top() <= nums2[i])
    //             stk.pop();
    //         // 栈顶元素就是 nums2[i] 的下一个更大的元素了，如果栈为空，则没有更大元素
    //         hashmap[nums2[i]] = (stk.empty() ? -1 : stk.top());
    //         // 当前元素入栈
    //         stk.push(nums2[i]);
    //     }

    //     // 遍历 nums1，用 hashmap 返回其结果
    //     vector<int> res;
    //     for (auto& num : nums1)
    //         res.push_back(hashmap[num]);

    //     return res;
    // }

    // 单调栈，从前向后遍历，维持单调递减栈
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        stack<int> stk;

        stk.push(0);
        // 从前向后遍历
        for (int i = 1; i < nums2.size(); ++i)
        {
            // nums2[i] 大于栈顶元素时可以出栈了
            while (!stk.empty() && nums2[i] > nums2[stk.top()])
            {
                int mid = stk.top();
                stk.pop();
                // 记录栈顶元素的下一个更大元素
                hashmap[nums2[mid]] = nums2[i];
            }
            // nums2[i] 小于等于栈顶元素直接入栈
            stk.push(i);
        }

        vector<int> res;
        for (auto& num : nums1)
        {
            // 在 hashmap 中说明有下一个更大元素
            if (hashmap.count(num))
                res.push_back(hashmap[num]);
            // 否则就没有，即 -1
            else
                res.push_back(-1);
        }

        return res;
    }
};
// @lc code=end

