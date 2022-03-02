/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
/** 
 * 回溯法
 */
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);

        return res;
    }

    void backtracking(vector<int>& nums, int start_idx)
    {
        // 类似于找子集，每个节点都是一种结果
        if (path.size() >= 2)
            res.push_back(path);
        
        // 在本层中选择
        unordered_set<int> hashset; // 去重
        vector<bool> visited(201); // 去重
        for (int i = start_idx; i < nums.size(); ++i)
        {
            // 只有大于 path 中的最后一个数才能进 path，因为是递增的，同时 path 不能为空
            if (!path.empty() && nums[i] < nums[start_idx - 1])
                continue;
            // 去重方法1.hashset
            // 树层去重，不能用 nums[i] == nums[i - 1] 了，因为没有排序，不一定是连续的数
            // if (hashset.count(nums[i]))
            //     continue;
            // hashset.insert(nums[i]);
            // 去重方法2.数组代替 hashset
            if (visited[nums[i] + 100])
                continue;
            visited[nums[i] + 100] = true;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

