/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
/** 
 * 回溯
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> path;
    int count;
    int max_count;
    int maxCoins(vector<int>& nums) {

    }

    void backtracking(vector<int>& nums, int start_idx)
    {
        // base case
        if (path.size() == nums.size())\
        {
            max_count = max(max_count, count);
            return;
        }

        // 递归
        for (int i = st)
    }
};
// @lc code=end

