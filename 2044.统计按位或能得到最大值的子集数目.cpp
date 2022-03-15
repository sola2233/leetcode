/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */

// @lc code=start
/** 
 * 回溯，非空子集一共有 2^n - 1 种，所以时间复杂度 o(2^n)
 */
#include <vector>
using namespace std;
class Solution {
public:
    int res; // 记录能得到最大结果的不同非空子集数目
    int max_path; // 记录最大按位或结果
    int path; // 记录某条路径的按位或结果
    int countMaxOrSubsets(vector<int>& nums) {
        max_path = 0;
        path = 0;
        res = 0;
        backtracking(nums, 0);

        return res;
    }

    /**
     * 回溯法，感觉和官方的写法不太一样，同时 path 如果放到参数里就不用回溯了 
     * @param start_idx 下一层递归开始的选择位置
     */
    void backtracking(vector<int>& nums, int start_idx)
    {
        // base case
        if (path > max_path)
        {
            max_path = path;
            res = 0;
        }
        if (path == max_path)
            res++;

        // 递归
        int temp = path;
        for (int i = start_idx; i < nums.size(); ++i)
        {
            path |= nums[i];
            backtracking(nums, i + 1);
            path &= temp;
        }
    }
};
// @lc code=end

