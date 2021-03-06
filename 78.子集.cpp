/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
/** 
 * 回溯法
 * 求取子集问题，不需要任何剪枝！因为子集就是要遍历整棵树
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

    /**
     * @param start_idx 下一层递归的起始搜索位置
     */
    void backtracking(vector<int>& nums, int start_idx)
    {
        // 子集问题每个节点都是一个答案，而组合问题每个叶子是一个答案
        res.push_back(path);
        
        // 在本层选择列表中做选择
        for (int i = start_idx; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

