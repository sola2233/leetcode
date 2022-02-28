/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
    // vector<bool> visited; // 记录候选人是否在 path 中
    int sum;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sum = 0;
        // visited.resize(candidates.size());
        // 去重和剪枝操作需要先排序
        sort(candidates.begin(), candidates.end());
        // 穷举
        backtracking(candidates, target, 0);

        return res;
    }

    /**
     * 回溯法 
     * @param start_idx 记录下一层递归搜索的起始位置
     */ 
    void backtracking(vector<int>& candidates, int target, int start_idx)
    {
        // 终止条件
        if (sum == target)
        {
            res.push_back(path);
            return;
        }

        // 在本层选择列表做选择
        for (int i = start_idx; i < candidates.size(); ++i)
        {
            // 剪枝，需要先对数组排序
            if (sum + candidates[i] > target)
                return; // 这里是提前返回，不用进入递归了
            // 去重写法1，去除本层相同的数，用 visited 防止去除树枝 path 中相同的数
            // if (i > 0 && candidates[i] == candidates[i - 1] && visited[i - 1] == false)
                // continue; // 注意这里只要跳过即可
            // 去重写法2，使用 start_idx 去重，因为 [0, start_idx - 1] 是已经在 path 中的数，
            // [start_idx, size() - 1] 是本层选则列表，只要 i 大于 start_idx就是在本层去重
            if (i > start_idx && candidates[i] == candidates[i - 1]) // 省略了 visited
                continue;
            // 做选择
            path.push_back(candidates[i]);
            sum += candidates[i];
            // visited[i] = true;
            backtracking(candidates, target, i + 1);
            path.pop_back();
            sum -= candidates[i];
            // visited[i] = false;
        }
    }
};
// @lc code=end

