/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
/** 
 * 回溯法
 * 参考https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
 * 还不太明白，先抄个答案
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * 主函数，输出一堆数的全排列 
     */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // 深度遍历+回溯
        backtracking(nums, 0, ans);
        return ans;
    }

    /**
     * 辅函数，回溯法 
     * @param nums 原数组
     * @param index 当前填到数组哪个位置
     * @param ans 返回的答案
     */
    void backtracking(vector<int> &nums, int index, vector<vector<int>> &ans)
    {
        // 递归终止条件，所有数都已经填完了
        if (index == nums.size() - 1)
        {
            // 保存这个叶子节点的结果
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            // 修改当前节点状态
            swap(nums[i], nums[index]);
            // 递归子节点
            backtracking(nums, index+1, ans);
            // 回改当前节点状态
            swap(nums[i], nums[index]);
        }
    }
};
// @lc code=end

