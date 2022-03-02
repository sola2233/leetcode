/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
/** 
 * 回溯法
 * 和 78 子集模板一样，但是多了 40 题的去重套路，这里是树层去重
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 排序
        sort(nums.begin(), nums.end());
        // 遍历
        backtracking(nums, 0);

        return res;
    }

    void backtracking(vector<int>& nums, int start_idx)
    {
        res.push_back(path);

        // 在本层做选择
        for (int i = start_idx; i < nums.size(); ++i)
        {
            // 同一层树枝上去重
            if (i > start_idx && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

