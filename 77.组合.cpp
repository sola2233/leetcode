/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
/** 
 * 回溯法，同46全排列
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res; // 存放返回结果
    vector<int> path; // 存放一条路径，即组合结果
    vector<vector<int>> combine(int n, int k) {
        backtracking(1, n, k);
        return res;
    }

    /**
     * 回溯法 
     * @param start_idx 记录下一层递归搜索的起始位置
     * @param n 一共 [1, n] n 个数
     * @param k 要找 k 个数的组合
     */ 
    void backtracking(int start_idx, int n, int k)
    {
        // 终止条件
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }

        // 加上剪枝优化
        for (int i = start_idx; i <= n - (k - path.size()) + 1; ++i)
        {
            // 修改当前节点状态
            path.push_back(i);
            // 递归子节点
            backtracking(i + 1, n, k);
            // 回改当前节点
            path.pop_back();
        }
    }
};
// @lc code=end

