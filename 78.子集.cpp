/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
/** 
 * 回溯法
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res; // 存放结果
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);

        return res;
    }

    // 回溯法
    void backtracking(vector<int>& nums, int start_idx)
    {
        // 没有终止条件，每个选择一个答案
        res.push_back(path);
        
        for (int i = start_idx; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

