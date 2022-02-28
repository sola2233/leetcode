/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
/** 
 * 回溯法，注意这题的剪枝策略需要先排序，不然会出错
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 剪枝的话要先排序，我也不知道为什么
        // 虽然多排了序，但是因为回溯时间复杂度很高，总体还是快了很多
        sort(candidates.begin(), candidates.end());
        // 回溯
        backtracking(candidates, target, 0);

        return res;
    }

    /**
     * 回溯法 
     * @param start_idx 记录下一层递归搜索的起始位置
     */
    void backtracking(vector<int>& candidates, int target, int start_idx)
    {
        // 终止条件，因为没有数量的要求，只有总和要求，加了剪枝这个可以不用了
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(path);
            return;
        }

        // 在选择列表做选择，选择列表 candidates[i : n-1]
        // 剪枝，如果 sum 已经大于 target，因为已经排了序，所以后面的 candidate 都大于 target
        // 此时这条枝干上包括后面的 candidate 都不用去穷举了，也就是不用进入后面的递归了
        for (int i = start_idx; i < candidates.size(); ++i)
        {
            // 剪枝
            if (sum + candidates[i] > target)
                return;
            // 做选择
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, i); // 不用加 1，这里表示数字可以重复
            path.pop_back(); // 回溯
            sum -= candidates[i];
        }
    }
};
// @lc code=end

