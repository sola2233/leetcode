/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
/** 
 * 回溯法
 */
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path; // 记录一条路径
    int sum; // 记录 path 中的总和
    vector<vector<int>> combinationSum3(int k, int n) {
        sum = 0;
        backtracking(1, k, n);

        return res;
    }

    /**
     * 回溯法 
     * @param start_idx 记录下一层递归搜索的起始位置
     * @param k 一共要 k 个数
     * @param n 目标和
     */
    void backtracking(int start_idx, int k, int n)
    {
        // 剪枝
        if (sum > n)
            return;

        // 终止条件
        if (path.size() == k)
        {
            // 满足条件
            if (sum == n)
                res.push_back(path);
            return;
        }

        // 做选择
        for (int i = start_idx; i <= 9; ++i)
        {
            path.push_back(i);
            sum += i;
            backtracking(i + 1, k, n);
            path.pop_back();
            sum -= i;
        }
    }
};
// @lc code=end

