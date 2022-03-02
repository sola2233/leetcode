/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
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
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visited;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 初始化
        visited.resize(nums.size());
        // 排序，去重用
        sort(nums.begin(), nums.end());
        // 回溯法
        backtracking(nums);

        return res;
    }

    void backtracking(vector<int>& nums)
    {
        // 终止条件
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        // 本层做选择
        for (int i = 0; i < nums.size(); ++i)
        {
            // 跳过树枝上已选则的数
            if (visited[i])
                continue;

            // 树层去重，前一个数为 false 表示是同一层的重复数
            // 如果前一个数为 true 表示一条树枝上的重复数，即前一个选择
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false)
                continue;

            visited[i] = true;
            path.push_back(nums[i]);
            backtracking(nums);
            path.pop_back();
            visited[i] = false;
        }
    }
};
// @lc code=end

