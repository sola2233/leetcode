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
#if 1   // 比较好的剪枝策略
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 剪枝的话要先排序，否则剪枝策略无法生效，因为后面的元素可能更小
        // 虽然多排了序，但是因为回溯时间复杂度很高，总体还是快了很多
        sort(candidates.begin(), candidates.end(), less<int>());
        // 回溯
        backtracking(candidates, target, 0, 0);

        return res;
    }

    /**
     * 回溯法 
     * @param start_idx 记录下一层递归搜索的起始位置
     * @param sum path 总和
     */
    void backtracking(vector<int>& candidates, int& target, int start_idx, int sum)
    {
        // 终止条件，因为没有数量的要求，只有总和要求
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
            // 剪枝，这里是在一层内剪枝，因为后面的元素肯定更大，所以无需尝试
            // 不会进入后序的递归，效率更高，但是需要排序
            int new_sum = sum + candidates[i];
            if (new_sum > target)
                break;            
            // 做选择
            path.push_back(candidates[i]);
            // 不用加 1，这里表示数字可以重复
            backtracking(candidates, target, i, new_sum); 
            path.pop_back(); // 回溯
        }
    }
#endif

#if 0   // 一般的剪枝策略

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return res;
    }

    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int& target, int start_idx, int sum)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(path);
            return;
        }

        for (int i = start_idx; i < candidates.size(); ++i)
        {
            path.push_back(candidates[i]);
            backtracking(candidates, target, i, sum + candidates[i]);
            path.pop_back();
        }
    }
#endif
};
// @lc code=end

