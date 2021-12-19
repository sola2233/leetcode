/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
/** 
 * 回溯法，同46全排列
 * 还不太懂，先抄个书上答案，同46
 */
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 主函数 
     */
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k, 0);
        int count = 0;
        backtracking(ans, comb, count, 1, n, k);
        return ans;
    }

    /**
     * 辅函数，回溯法 
     * @param 
     * @return 
     */
    void backtracking(vector<vector<int>> &ans, vector<int>& comb, int &count, int pos, int n, int k)
    {
        if (count == k)
        {
            ans.push_back(comb);
            return;
        }

        for (int i = pos; i <= n; ++i)
        {
            // 修改当前节点状态
            comb[count++] = i;
            // 递归子节点
            backtracking(ans, comb, count, i + 1, n, k);
            // 回改当前节点
            --count;
        }
    }
};
// @lc code=end

