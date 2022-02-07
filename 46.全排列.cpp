/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
/** 
 * 回溯法
 * 回溯法三要素：路径、选择列表、结束条件
 * 回溯法框架：大框架就是dfs遍历，相当于遍历一棵决策树
 * 参考https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
 * 其中交换元素不太容易理解，可以改用标记数组来作为选择列表，只在未标记的元素中选择，需要 o(n) 的空间
 * 回溯法时间复杂度 o(n!)
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

        // 在选择列表中做选择，相当于遍历决策树每个节点，此处没有显示记录选择列表，而是通过交换元素
        for (int i = index; i < nums.size(); ++i)
        {
            // 做选择，修改当前节点状态
            swap(nums[i], nums[index]);
            // 进入下一层决策树，递归子节点
            backtracking(nums, index+1, ans);
            // 撤销选择，回改当前节点状态
            swap(nums[i], nums[index]);
        }
    }
};
// @lc code=end

