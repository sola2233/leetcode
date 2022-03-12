/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
/** 
 * 用两个辅助数组
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // left[i] 为 nums[i] 左侧所有数的乘积
        vector<int> left(n, 1);
        for (int i = 1; i < n; ++i)
            left[i] = left[i - 1] * nums[i - 1];
        // right[i] 为 nums[i] 右侧所有数的乘积
        vector<int> right(n, 1);
        for (int i = n - 2; i >= 0; --i)
            right[i] = right[i + 1] * nums[i + 1];
        // 计算结果
        for (int i = 0; i < n; ++i)
            nums[i] = left[i] * right[i];
        return nums;
    }
};
// @lc code=end

