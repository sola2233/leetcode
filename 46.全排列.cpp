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
 * 其中交换元素不太容易理解，可以改用访问数组来作为选择列表，只在未标记的元素中选择，需要 o(n) 的空间
 * 回溯法时间复杂度 o(n!)
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> visited; // 访问数组
    vector<int> path; // 路径，记录一条树枝，交换数组不需要，直接用 nums 就行了
    vector<vector<int>> permute(vector<int>& nums) {
        // 交换元素
        // backtracking1(nums, 0);
        // 访问数组
        visited.resize(nums.size());
        backtracking2(nums);

        return res;
    }

    /**
     * 辅函数，回溯法，通过交换元素
     * @param start_idx 下一层递归的起始搜索位置
     */
    void backtracking1(vector<int> &nums, int start_idx)
    {
        // 递归终止条件，所有数都已经填完了，到达叶子节点
        if (start_idx == nums.size() - 1)
        {
            res.push_back(nums);
            return;
        }

        // 在选择列表中做选择，相当于遍历决策树每个节点，此处没有显示记录选择列表，而是通过交换元素
        for (int i = start_idx; i < nums.size(); ++i)
        {
            // 做选择，修改当前节点状态
            swap(nums[i], nums[start_idx]);
            // 进入下一层决策树，递归子节点
            backtracking1(nums, start_idx + 1);
            // 撤销选择，回改当前节点状态
            swap(nums[i], nums[start_idx]);
        }
    }

    /**
     * 回溯法，通过访问数组 
     */
    void backtracking2(vector<int>& nums)
    {
        // 终止条件
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        // 在本层做选择，没有 start_idx 了
        for (int i = 0; i < nums.size(); ++i)
        {
            // 跳过树枝上已经用过的数
            if (visited[i])
                continue;
            
            visited[i] = true;
            path.push_back(nums[i]);
            backtracking2(nums);
            path.pop_back();
            visited[i] = false;
        }
    }
};
// @lc code=end

