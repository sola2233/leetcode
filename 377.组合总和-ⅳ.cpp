/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
/** 
 * 回溯法
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int res;
    int sum;
    int combinationSum4(vector<int>& nums, int target) {
        res = 0;
        sum = 0;
        sort(nums.begin(), nums.end());
        backtracking(nums, target, 0);
        return res;
    }

    void backtracking(vector<int>& nums, int target, int start_idx)
    {
        // 剪枝
        if (sum > target)
            return;
        // 终止条件
        if (sum == target)
        {
            res++;
            return;
        }

        // 在本层做选择，从下标 0 开始，因为顺序不同的序列视作不同组合，选择范围为整个 nums
        for (int i = 0; i < nums.size(); ++i)
        {
            // 本层剪枝
            if (sum + nums[i] > target)
                break;
            sum += nums[i];
            backtracking(nums, target, i); // 不用加 1，表示可以重复选择
            sum -= nums[i];
        }
    }
};
// @lc code=end

